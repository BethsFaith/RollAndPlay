//
// Created by BethsFaith on 19.02.2024.
//

#include "Worker.hpp"

#include <utility>

namespace Threads {
    Worker::Worker(std::shared_ptr<std::mutex> mutex, std::condition_variable& conditionVariable,
                   const std::function<void()>& func)
        : _mutex(std::move(mutex)),
          _cv(conditionVariable),
          _workFunction(func) {}

    Worker::~Worker() {
        if (!_stopped) {
            stop();
        }
    }

    void Worker::start(int delayMilliseconds) {
        _worker = std::make_unique<std::thread>(&Worker::run, this, delayMilliseconds);

        std::lock_guard lg(*_mutex);
        _start = true;
        _cv.notify_one();
    }

    void Worker::run(int delay) {
        std::unique_lock lk(*_mutex);
        _cv.wait(lk, [this] {
            return _start;
        });

        while (!_needToStop) {
            _workFunction();

            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }

        _stopped = true;

        lk.unlock();
        _cv.notify_one();
    }

    void Worker::stop() {
        _needToStop = true;

        std::unique_lock lk(*_mutex);
        _cv.wait(lk, [this] {
            return _stopped;
        });
        _worker->join();
        lk.unlock();

        _stopped = false;
        _needToStop = false;
    }

    void Worker::determinate() {
        _needToStop = true;

        _worker->join();
    }
}    //namespace Threads
