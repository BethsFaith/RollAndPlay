#include <iostream>
#include "GLWindow.h"

int main() {
    GLWindow window("RollAndPlay - Game System");

    window.setClearColor({0.0f, 0.0f, 0.0f, 0.0f});

    window.run();

    return 0;
}
