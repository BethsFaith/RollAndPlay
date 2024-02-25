#include "MainWindow.hpp"
#include "logger/Logger.hpp"

int main() {
    Logger::set_level(spdlog::level::debug); // Set global log level to debug
    // change log pattern
//    Logger::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
//    Logger::error("Some error message with arg: {}", 1);
//
//    Logger::warn("Easy padding in numbers like {:08d}", 12);
//    Logger::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
//    Logger::info("Support for floats {:03.2f}", 1.23456);
//    Logger::info("Positional args are {1} {0}..", "too", "supported");
//    Logger::info("{:<30}", "left aligned");

    MainWindow::init("RollAndPlay - Game System", "../../config.json");

    auto window = MainWindow::getInstance();

    window->setClearColor(glm::vec4{0.2f});

    window->run();

    MainWindow::free();

    return 0;
}
