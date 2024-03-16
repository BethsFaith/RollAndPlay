//
// Created by VerOchka on 06.10.2023.
//

#include "MainWindow.hpp"

MainWindow* MainWindow::instance = nullptr;

MainWindow::MainWindow(const char* title, const std::string& configFilePath) {
    Config::Config config(configFilePath);

    int height, width;
    Config::pullDesktopResolution(width, height);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_DECORATED, false);

    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (_window == nullptr) {
        throw std::runtime_error("Failed to initialize window");
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, frameBufferSizeCallback);
    glfwSetCharModsCallback(_window, charModsCallback);
    stbi_set_flip_vertically_on_load(true);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    GraphicLib::Objects::Techniques::TextTechnique::initTextRendering(width, height, config.getFontPath("gui"), 20);

    _canvas = std::make_shared<GraphicLib::Objects::PickableTexture>();
    _canvas->init(width, height);
    _view = std::make_shared<View>(glm::vec2{-0.9f, -0.83f},
                                   glm::vec2{0.9f, 0.83f},
                                   Pages::Style::DARK_GRAY,
                                   _canvas);

    auto guiShaderPath = config.getShaderPath("gui");
    auto selectableShaderPath = config.getShaderPath("selectable");
    auto textShaderPath = config.getShaderPath("text");
    auto textureShaderPath = config.getShaderPath("texture");

    auto guiShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>(guiShaderPath.vertex, guiShaderPath.fragment);
    GraphicLib::GuiObjects::Gui::setColorShader(guiShader);

    GraphicLib::GuiObjects::Gui::setSelectableShader(
        std::make_shared<GraphicLib::Shaders::ShaderProgram>(selectableShaderPath.vertex,
                                                             selectableShaderPath.fragment));

    GraphicLib::GuiObjects::Gui::setTextShader(
        std::make_shared<GraphicLib::Shaders::ShaderProgram>(textShaderPath.vertex, textShaderPath.fragment));

    GraphicLib::GuiObjects::Gui::setTextureShader(
        std::make_shared<GraphicLib::Shaders::ShaderProgram>(textureShaderPath.vertex, textureShaderPath.fragment));

    auto host = config.getNetValue("host");
    auto port = config.getNetValue("port");
    auto domain = config.getNetValue("domain");
    Pages::BasePage::setCommonData(
        {.clientSession = std::make_shared<Net::ApiClient>(host, port, domain, new Net::Route("../../paths.json"))});

    GraphicLib::GuiObjects::Carriage::WindowWidth = width;
    GraphicLib::GuiObjects::Carriage::WindowHeight = height;
    GraphicLib::GuiObjects::ScrollBox::windowHeight = height;
    GraphicLib::GuiObjects::ScrollBox::windowWidth = width;

    Pages::PageStyleParser styleParser(config);
    styleParser.parse("../../style.json");

    auto systemPage = std::make_shared<Pages::SystemPage>(_canvas, styleParser.getWidgetBuilder("system"));
    auto characteristicPage = std::make_shared<Pages::CharacteristicPage>(
        _canvas,
        styleParser.getWidgetBuilder("characteristic"));
    auto skillPage = std::make_shared<Pages::SkillPage>(_canvas, styleParser.getWidgetBuilder("skill"));
    auto actionPage = std::make_shared<Pages::ActionPage>(_canvas, styleParser.getWidgetBuilder("action"));
    auto itemPage = std::make_shared<Pages::ItemPage>(
        _canvas,
        styleParser.getWidgetBuilder("item"));
    auto racePage = std::make_shared<Pages::RacePage>(_canvas, styleParser.getWidgetBuilder("race"));
    auto loginPage = std::make_shared<Pages::LoginPage>(_canvas, styleParser.getWidgetBuilder("login"));
    auto registrationPage = std::make_shared<Pages::RegistrationPage>(_canvas,
                                                                      styleParser.getWidgetBuilder("registration"));

    _view->addPage(View::PageTag::SYSTEM, systemPage);
    _view->addPage(View::PageTag::CHARACTERISTIC, characteristicPage);
    _view->addPage(View::PageTag::SKILL, skillPage);
    _view->addPage(View::PageTag::ACTION, actionPage);
    _view->addPage(View::PageTag::ITEM, itemPage);
    _view->addPage(View::PageTag::RACE, racePage);
    _view->addPage(View::PageTag::AUTHORIZATION, loginPage);
    _view->addPage(View::PageTag::REGISTRATION, registrationPage);
}

MainWindow::~MainWindow() {
    _canvas.reset();
    _view.reset();

    GraphicLib::Objects::Techniques::TextTechnique::freeTextRendering();

    if (_window != nullptr) {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}

void MainWindow::init(const char* title, const std::string& configFilePath) {
    instance = new MainWindow(title, configFilePath);

    glfwSetMouseButtonCallback(instance->_window, mouseButtonCallback);
    glfwSetCursorPosCallback(instance->_window, mouseInputCallback);
    glfwSetScrollCallback(instance->_window, mouseScrollCallback);
    glfwSetDropCallback(instance->_window, dropCallback);
}

void MainWindow::free() {
    delete instance;
}

GLFWwindow* MainWindow::getWindow() const {
    return _window;
}

MainWindow* MainWindow::getInstance() {
    return instance;
}

float MainWindow::getDeltaTime() const {
    return _delta_time;
}

void MainWindow::setClearColor(const glm::vec4& clearColor) {
    _clearColor = clearColor;
}

void MainWindow::run() {
    using namespace GraphicLib;

    while (!shouldClose()) {
        clearColor();
        updateDeltaTime();

        int width, height;
        glfwGetWindowSize(_window, &width, &height);

        _view->processKeyboardInput(_window);
        _view->display(width, height);

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
    auto currentFrame = (float)glfwGetTime();

    _delta_time = currentFrame - _last_frame;
    _last_frame = currentFrame;
}

bool MainWindow::shouldClose() {
    return _view->needToClose() || glfwWindowShouldClose(_window);
}

void MainWindow::mouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods) {
    instance->_view->processMouseButton(window, mouseButton, action, mods);
}

void MainWindow::mouseInputCallback(GLFWwindow* window, double xPos, double yPos) {
    instance->_view->processMouseCursor(window, xPos, yPos);
}

void MainWindow::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    instance->_view->processMouseScroll(window, xOffset, yOffset);
}

void MainWindow::charModsCallback(GLFWwindow* window, unsigned int codepoint, int mods) {
    instance->_view->processCharMods(window, codepoint, mods);
}

void MainWindow::dropCallback(GLFWwindow* window, int count, const char** paths) {
    instance->_view->processDrop(window, count, paths);
}

void MainWindow::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    instance->_canvas->init(width, height);
}
