#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "MainWindow.hpp"

int main() {
    MainWindow::init("RollAndPlay - Game System", "../../config.json");

    auto window = MainWindow::getInstance();

    window->setClearColor(glm::vec4{0.2f});

    window->run();

    MainWindow::free();

    return 0;
}
