#include <iostream>
#include "MainWindow.hpp"

int main() {
    MainWindow::init("RollAndPlay - Game System");

    auto window = MainWindow::getInstance();

    window->setClearColor({0.0f, 0.0f, 0.0f, 0.0f});

    window->run();

    MainWindow::free();

    return 0;
}
