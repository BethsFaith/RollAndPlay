//
// Created by BethsFaith on 19.02.2024.
//

#ifndef INC_1_BIN_WORKER_HPP
#define INC_1_BIN_WORKER_HPP

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>

namespace Threads {
    class Worker {
    public:
        using Ptr = std::unique_ptr<Worker>;

        Worker(std::shared_ptr<std::mutex> mutex, std::condition_variable& conditionVariable,
               const std::function<void()>& func);
        ~Worker();

        void start(int delayMilliseconds);
        void stop();
        void determinate();

    private:
        void run(int delay);

        std::unique_ptr<std::thread> _worker;
        std::condition_variable& _cv;
        std::shared_ptr<std::mutex> _mutex;
        std::function<void()> _workFunction;

        bool _stopped = false;
        bool _start = false;
        bool _needToStop = false;
    };
}    //namespace Threads

#endif    //INC_1_BIN_WORKER_HPP
