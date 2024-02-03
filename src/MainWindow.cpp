//
// Created by VerOchka on 06.10.2023.
//

#include "MainWindow.hpp"

MainWindow* MainWindow::instance = nullptr;

MainWindow::MainWindow(const char* title, const std::string& configFilePath) {
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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    GraphicLib::Techniques::TextTechnique::initTextRendering(width, height, config->getFontPath("gui"), 20);

    auto canvas = std::make_shared<GraphicLib::PickableTexture>();
    canvas->init(width, height);

    auto guiShaderPath = config->getShaderPath("gui");
    auto selectableShaderPath = config->getShaderPath("selectable");
    auto textShaderPath = config->getShaderPath("text");
    auto textureShaderPath = config->getShaderPath("texture");

    auto guiShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (guiShaderPath.vertex,
             guiShaderPath.fragment);
    Gui::setColorShader(guiShader);

    Gui::setSelectableShader(std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (selectableShaderPath.vertex,
             selectableShaderPath.fragment));

    Gui::setTextShader(std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (textShaderPath.vertex,
             textShaderPath.fragment));

    Gui::setTextureShader(std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (textureShaderPath.vertex,
             textureShaderPath.fragment));

    _view = std::make_shared<View>(0, 0,  Widgets::Styles::Color::DARK_GRAY, canvas, guiShader);

    auto host = config->getNetValue("host");
    auto port = config->getNetValue("port");
    auto domain = config->getNetValue("domain");
    Pages::BasePage::setCommonData({.session = std::make_shared<Net::HttpSession>(host, port, domain)});

    GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle = std::make_shared<GraphicLib::Primitives::Rectangle>(
        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                                    .with_texture_coords = false,
                                                    .with_tangent = false,
                                                    .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    auto textureRectangle = std::make_shared<GraphicLib::Primitives::Rectangle>(
        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                                    .with_texture_coords = true,
                                                    .with_tangent = false,
                                                    .with_bitangent = false});
    textureRectangle->bindData(GL_STATIC_DRAW);

    Widgets::Styles::ButtonStyle::Ptr buttonStyle = std::make_shared<Widgets::Styles::ButtonStyle>();
    buttonStyle->color = Widgets::Styles::GRAY;
    buttonStyle->traceColor = Widgets::Styles::WHITE;
    buttonStyle->pressColor = Widgets::Styles::BLUE;
    buttonStyle->labelParams = {.color = Widgets::Styles::WHITE, .size = 1.0f};
    buttonStyle->scale = {0.1f, 0.1f};
    buttonStyle->figure = rectangle;

    Widgets::Styles::TextInputFieldStyle::Ptr textInputFieldStyle = std::make_shared<Widgets::Styles::TextInputFieldStyle>();
    textInputFieldStyle->labelParams = {.color = Widgets::Styles::WHITE, .size = 1.0f};
    textInputFieldStyle->inputParams = {.color = Widgets::Styles::BLACK, .size = 1.4f};
    textInputFieldStyle->color = Widgets::Styles::LIGHT_GRAY;
    textInputFieldStyle->traceColor = Widgets::Styles::WHITE;
    textInputFieldStyle->scale = {0.7f, 0.1f};
    textInputFieldStyle->figure = rectangle;

    Widgets::Styles::TextBoxStyle::Ptr textBoxStyle = std::make_shared<Widgets::Styles::TextBoxStyle>();
    textBoxStyle->color = Widgets::Styles::DARK_GRAY;
    textBoxStyle->scale = {0.7f, 0.1f};
    textBoxStyle->textLabelParams = {.color = Widgets::Styles::WHITE, .size = 1.0f};

    Widgets::Styles::ImageButtonStyle::Ptr imageButtonStyle = std::make_shared<Widgets::Styles::ImageButtonStyle>();
    imageButtonStyle->scale = {0.1f, 0.15f};
    imageButtonStyle->defaultTexturePath = Config::Config::get()->getTexturePath("default");
    imageButtonStyle->defaultTextureIndex = 0;
    imageButtonStyle->traceColor = Widgets::Styles::WHITE;
    imageButtonStyle->labelParams = {.color = Widgets::Styles::WHITE, .size = 1.0f};
    imageButtonStyle->figure = textureRectangle;

    Widgets::Styles::LayoutStyle::Ptr layoutStyle = std::make_shared<Widgets::Styles::LayoutStyle>();
    layoutStyle->widgetOffset = 0.1f;

    Widgets::WidgetBuilder::Ptr widgetBuilder = std::make_shared<Widgets::WidgetBuilder>();
    widgetBuilder->addWidgetStyle(Widgets::BUTTON, buttonStyle);
    widgetBuilder->addWidgetStyle(Widgets::TEXT_INPUT_FIELD, textInputFieldStyle);
    widgetBuilder->addWidgetStyle(Widgets::IMAGE_BUTTON, imageButtonStyle);
    widgetBuilder->addWidgetStyle(Widgets::TEXT_BOX, textBoxStyle);
    widgetBuilder->addWidgetStyle(Widgets::HORIZONTAL_LAYOUT, layoutStyle);
    widgetBuilder->addWidgetStyle(Widgets::VERTICAL_LAYOUT, layoutStyle);

    auto systemPage = std::make_shared<Pages::SystemPage>(canvas, widgetBuilder);
    auto skillPage = std::make_shared<Pages::SkillPage>(canvas, widgetBuilder);
    auto racePage = std::make_shared<Pages::RacePage>(canvas, widgetBuilder);
    auto loginPage = std::make_shared<Pages::LoginPage>(canvas, widgetBuilder);
    auto registrationPage = std::make_shared<Pages::RegistrationPage>(canvas, widgetBuilder);

    _view->addPage(View::PageTag::SYSTEM, systemPage);
    _view->addPage(View::PageTag::SKILL, skillPage);
    _view->addPage(View::PageTag::RACE, racePage);
    _view->addPage(View::PageTag::AUTHORIZATION, loginPage);
    _view->addPage(View::PageTag::REGISTRATION, registrationPage);
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

void MainWindow::init(const char* title, const std::string& configFilePath) {
    instance = new MainWindow(title, configFilePath);

    glfwSetMouseButtonCallback(instance->_window, mouseButtonCallback);
    glfwSetCursorPosCallback(instance->_window, mouseInputCallback);
    glfwSetScrollCallback(instance->_window, mouseScrollCallback);
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
    auto currentFrame = (float)glfwGetTime();

    _delta_time = currentFrame - _last_frame;
    _last_frame = currentFrame;
}

bool MainWindow::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void MainWindow::mouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods) {
    instance->_view->processMouseButton(window, mouseButton, action, mods);
}

void MainWindow::mouseInputCallback(GLFWwindow* window, double xPos, double yPos) {
    instance->_view->processMouseCursor(window, xPos, yPos);
}

void MainWindow::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    instance->_view->processMouseCursor(window, xOffset, yOffset);
}

void MainWindow::charModsCallback(GLFWwindow* window, unsigned int codepoint, int mods) {
    instance->_view->processCharMods(window, codepoint, mods);
}

void MainWindow::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
