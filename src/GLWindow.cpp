//
// Created by VerOchka on 06.10.2023.
//

#include "GLWindow.hpp"

GLWindow::GLWindow(const char *title) {
    RECT desktop;

    const auto hDesktop = GetDesktopWindow();

    GetWindowRect(hDesktop, &desktop);

    init(desktop.right, desktop.bottom, title);
}

GLWindow::GLWindow(const int &width, const int &height, const char *title) {
    init(width, height, title);
}

GLWindow::~GLWindow() {
    glfwTerminate();
}

void GLWindow::init(const int &width, const int &height, const char *title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (_window == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize window");
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, frameBufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

void GLWindow::frameBufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

float GLWindow::getDeltaTime() const {
    return _delta_time;
}

GLFWwindow *GLWindow::getWindow() const {
    return _window;
}

void GLWindow::setClearColor(const glm::vec4 &clearColor) {
    _clearColor = clearColor;
}

void GLWindow::run() {
    while (!shouldClose()) {
        clearColor();
        updateDeltaTime();

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

void GLWindow::clearColor() const {
    glClearColor(_clearColor.x, _clearColor.y, _clearColor.z, _clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWindow::updateDeltaTime() {
    auto currentFrame = (float)glfwGetTime();

    _delta_time = currentFrame - _last_frame;
    _last_frame = currentFrame;
}

bool GLWindow::shouldClose() {
    return glfwWindowShouldClose(_window);
}
