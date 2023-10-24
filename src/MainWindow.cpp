//
// Created by VerOchka on 06.10.2023.
//

#include "MainWindow.hpp"

MainWindow *MainWindow::instance = nullptr;

MainWindow::MainWindow(const char *title) {
    RECT desktop;

    const auto hDesktop = GetDesktopWindow();

    GetWindowRect(hDesktop, &desktop);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(desktop.right, desktop.bottom, title, nullptr, nullptr);

    if (_window == nullptr) {
        throw std::runtime_error("Failed to initialize window");
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, frameBufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    _gui = std::make_shared<Gui>(desktop.right, desktop.bottom);
}

MainWindow::~MainWindow() {
    _controller.free();

    _buttons.clear();
    _gui.reset();

    if (_window != nullptr) {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}

void MainWindow::init(const char *title) {
    instance = new MainWindow(title);

    glfwSetMouseButtonCallback(instance->_window, mouseButtonCallback);
    glfwSetCursorPosCallback(instance->_window, mouseInputCallback);
    glfwSetScrollCallback(instance->_window, mouseScrollCallback);
}

void MainWindow::free() {
    delete instance;
}

GLFWwindow *MainWindow::getWindow() const {
    return _window;
}

MainWindow *MainWindow::getInstance() {
    return instance;
}

float MainWindow::getDeltaTime() const {
    return _delta_time;
}

void MainWindow::setClearColor(const glm::vec4 &clearColor) {
    _clearColor = clearColor;
}

void MainWindow::run() {
    using namespace GraphicLib;

    Primitives::AbstractPrimitive::Ptr rectangle =
            std::make_shared<Primitives::Rectangle>(
                    Primitives::Primitive::Settings{.with_normals = false,
                            .with_texture_coords = false,
                            .with_tangent = false,
                            .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    float startOffset = -8.7f;
    for (int i{}; i < 5; ++i) {
        auto button = std::make_shared<Forms::Button>(startOffset,9.0f);

        button->color = Forms::Color::GREY;

        button->text = "Button" + std::to_string(i);
        _gui->addButton(button, rectangle);
        _controller.addButton(button);
        _buttons.push_back(button);

        startOffset += 1.3;
    }
    _buttons[0]->setPressCallback([&](){
        std::cout << "1PRESS" << std::endl;
    });
    _buttons[1]->setPressCallback([&](){
        std::cout << "2PRESS" << std::endl;
    });
    _buttons[2]->setPressCallback([&](){
        std::cout << "3PRESS" << std::endl;
    });
    _buttons[3]->setPressCallback([&](){
        std::cout << "4PRESS" << std::endl;
    });
    _buttons[4]->setPressCallback([&](){
        std::cout << "5PRESS" << std::endl;
    });

    while (!shouldClose()) {
        clearColor();
        updateDeltaTime();

        _controller.processKeyboardInput(_window);
        _gui->draw();

//        if (_view != nullptr) {
//            _view->processKeyboardInput(_window);
//            _view->draw();
//        }

        glfwSwapBuffers(_window);
        glfwPollEvents();

        Sleep(100);
    }
}

void MainWindow::clearColor() const {
    glClearColor(_clearColor.x, _clearColor.y, _clearColor.z, _clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MainWindow::updateDeltaTime() {
    auto currentFrame = (float) glfwGetTime();

    _delta_time = currentFrame - _last_frame;
    _last_frame = currentFrame;
}

bool MainWindow::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void MainWindow::mouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods) {
    instance->_controller.processMouseButton(window, mouseButton, action, mods);
}

void MainWindow::mouseInputCallback(GLFWwindow *window, double xPos, double yPos) {
    instance->_controller.processMouseCursor(window, xPos, yPos);
}

void MainWindow::mouseScrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
    instance->_controller.processMouseCursor(window, xOffset, yOffset);
}

void MainWindow::frameBufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}