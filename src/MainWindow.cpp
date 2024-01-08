//
// Created by VerOchka on 06.10.2023.
//

#include "MainWindow.hpp"

MainWindow *MainWindow::instance = nullptr;

MainWindow::MainWindow(const char *title, const std::string &configFilePath) {
    Config::Config::init(configFilePath);
    auto config = Config::Config::get();

    int height, width;
    Config::pullDesktopResolution(width, height);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (_window == nullptr) {
        throw std::runtime_error("Failed to initialize window");
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, frameBufferSizeCallback);
    glfwSetCharModsCallback(_window, charModsCallback);
    stbi_set_flip_vertically_on_load(true);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    GraphicLib::Techniques::TextTechnique::initTextRendering(width, height,
                                                           config->getFontPath("gui"), 20);

    auto canvas = std::make_shared<GraphicLib::PickableTexture>();
    canvas->init(width, height);

    _view = std::make_shared<ViewWindow>(0, 0, Forms::Color::DARK_GRAY, canvas);

    auto systemPage = std::make_shared<Pages::SystemPage>(canvas);
    auto skillPage = std::make_shared<Pages::SkillPage>(canvas);
    auto racePage = std::make_shared<Pages::RacePage>(canvas);
    auto loginPage = std::make_shared<Pages::LoginPage>(canvas);
    auto registrationPage = std::make_shared<Pages::RegistrationPage>(canvas);

    _view->addPage(ViewWindow::PageTag::SYSTEM, systemPage);
    _view->addPage(ViewWindow::PageTag::SKILL, skillPage);
    _view->addPage(ViewWindow::PageTag::RACE, racePage);
    _view->addPage(ViewWindow::PageTag::AUTHORIZATION, loginPage);
    _view->addPage(ViewWindow::PageTag::REGISTRATION, registrationPage);
}

MainWindow::~MainWindow() {
    _view.reset();

    GraphicLib::Techniques::TextTechnique::freeTextRendering();

    if (_window != nullptr) {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();

    Config::Config::free();
}

void MainWindow::init(const char *title, const std::string &configFilePath) {
    instance = new MainWindow(title, configFilePath);

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

    while (!shouldClose()) {
        clearColor();
        updateDeltaTime();

        if (_view != nullptr) {
            _view->processKeyboardInput(_window);
            _view->display();
        }

        glfwSwapBuffers(_window);
        glfwPollEvents();

        Sleep(10);
    }
}

void MainWindow::clearColor() const {
    glClearColor(_clearColor.x, _clearColor.y, _clearColor.z, _clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void MainWindow::updateDeltaTime() {
    auto currentFrame = (float) glfwGetTime();

    _delta_time = currentFrame - _last_frame;
    _last_frame = currentFrame;
}

bool MainWindow::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void MainWindow::mouseButtonCallback(GLFWwindow *window, int mouseButton, int action, int mods) {
    instance->_view->processMouseButton(window, mouseButton, action, mods);
}

void MainWindow::mouseInputCallback(GLFWwindow *window, double xPos, double yPos) {
    instance->_view->processMouseCursor(window, xPos, yPos);
}

void MainWindow::mouseScrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
    instance->_view->processMouseCursor(window, xOffset, yOffset);
}

void MainWindow::charModsCallback(GLFWwindow *window, unsigned int codepoint, int mods) {
    instance->_view->processCharMods(window, codepoint, mods);
}

void MainWindow::frameBufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
