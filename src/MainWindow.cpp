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

    _gui = std::make_shared<Gui>();
    _controller.init(desktop.right, desktop.bottom);
}

MainWindow::~MainWindow() {
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
    Graphic::AbstractPrimitive::Ptr rectangle =
            std::make_shared<Graphic::Rectangle>(
                    Graphic::Primitive::Settings{.with_normals = false,
                            .with_texture_coords = false,
                            .with_tangent = false,
                            .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    auto button = std::make_shared<Forms::Button>(-8.7f,9.0f);
    auto button2 = std::make_shared<Forms::Button>(-7.4f, 9.0f);
    auto button3 = std::make_shared<Forms::Button>(-6.1f, 9.0f);
    _buttons.push_back(button);
    _buttons.push_back(button2);
    _buttons.push_back(button3);

    button->color = Forms::Color::VIOLET;
    button2->color = Forms::Color::GREY;
    button3->color = Forms::Color::GREY;

    button->setPressCallback([](){
        std::cout << "VIOLET PRESS" << std::endl;
    });
    button2->setPressCallback([](){
        std::cout << "GREY1 PRESS" << std::endl;
    });
    button3->setPressCallback([](){
        std::cout << "GREY2 PRESS" << std::endl;
    });

    _gui->addButton(button, rectangle);
    _gui->addButton(button2, rectangle);
    _gui->addButton(button3, rectangle);

    _controller.addButton(button);
    _controller.addButton(button2);
    _controller.addButton(button3);

    auto shader = std::make_shared<Graphic::Shaders::ShaderProgram>
            (R"(..\..\rsrc\shaders\gui.vert)",
             R"(..\..\rsrc\shaders\select.frag)");

    while (!shouldClose()) {
        clearColor();
        updateDeltaTime();

        _controller.processKeyboardInput(_window);
        _gui->draw();

        shader->use();
        _controller.getPicking().enableWriting();
        for (auto& button : _buttons) {
            glm::mat4 trans = glm::mat4(1.0f);
            trans = glm::scale(trans, glm::vec3(0.1, 0.1, 0.0f));
            trans = glm::translate(trans, glm::vec3(button->getXOffset(),button->getYOffset(), 0.0f));

            shader->set4FloatMat("Transform", glm::value_ptr(trans));
            shader->setFloat("gDrawIndex", button->getId());
            shader->setFloat("gObjectIndex", button->getId());

            rectangle->draw();
        }
        _controller.getPicking().disableWriting();

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