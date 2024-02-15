cmake_minimum_required(VERSION 3.25)
project(RollAndPlay)

set(CMAKE_CXX_STANDARD 20)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)
add_subdirectory(libs/GraphicLib)

conan_cmake_run(CONANFILE conanfile.txt
        INSTALL_FOLDER ${CMAKE_BINARY_DIR}
        BASIC_SETUP
        BUILD missing)

add_executable(RollAndPlay
        src/main.cpp
        src/Gui.cpp
        src/MainWindow.cpp
        src/View.cpp
        src/ViewDrawer.cpp
        src/data/Skill.cpp
        src/data/Action.cpp
        src/data/CharacterClass.cpp
        src/data/System.cpp
        src/data/SkillCategory.cpp
        src/data/User.cpp
        src/data/DataFactory.cpp
        src/data/Race.cpp
        src/data/convert/Convert.cpp
        src/data/graphic/Model.cpp
        src/widgets/styles/Color.cpp
        src/widgets/Button.cpp
        src/widgets/graphic/Form.cpp
        src/widgets/graphic/PickableForm.cpp
        src/widgets/Widget.cpp
        src/widgets/TextInputField.cpp
        src/widgets/ImageButton.cpp
        src/widgets/Carriage.cpp
        src/widgets/TextBox.cpp
        src/widgets/MenuBar.cpp
        src/widgets/Layout.cpp
        src/widgets/HorizontalLayout.cpp
        src/widgets/VerticalLayout.cpp
        src/widgets/ImageBox.cpp
        src/widgets/WidgetFactory.cpp
        src/widgets/WidgetBuilder.cpp
        src/pages/BasePage.cpp
        src/pages/SystemPage.cpp
        src/pages/SkillPage.cpp
        src/pages/RacePage.cpp
        src/pages/LoginPage.cpp
        src/pages/RegistrationPage.cpp
        src/controllers/GuiController.cpp
        src/controllers/TextInputContoller.cpp
        src/controllers/CommonController.cpp
        src/controllers/ButtonController.cpp
        src/controllers/WidgetControllerFactory.cpp
        src/controllers/ImageButtonController.cpp
        src/controllers/MenuBarController.cpp
        src/controllers/LayoutController.cpp
        src/data/storage/StreamWriter.cpp
        src/data/storage/StreamReader.cpp
        src/data/DataStorage.cpp
        src/config/Parser.cpp
        src/config/Config.cpp
        src/net/ApiClient.cpp
        src/net/HttpRequest.cpp
        src/net/HttpResponse.cpp
        src/net/HttpSession.cpp
        src/net/Route.cpp
        )


target_link_libraries(RollAndPlay ${CONAN_LIBS} GraphicLib)
