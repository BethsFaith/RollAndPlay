#include <iostream>
#include "MainWindow.hpp"

int main() {
    MainWindow::init("RollAndPlay - Game System");

    auto window = MainWindow::getInstance();

    window->setClearColor(glm::vec4{0.2f});

    window->run();

    MainWindow::free();

    return 0;
}
