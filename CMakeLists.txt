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
add_subdirectory(libs/graphicLib)

conan_cmake_run(CONANFILE conanfile.txt
        INSTALL_FOLDER ${CMAKE_BINARY_DIR}
        BASIC_SETUP
        BUILD missing)

add_executable(RollAndPlay
        src/main.cpp
        src/data/Skill.cpp
        src/data/Action.cpp
        src/data/CharacterClass.cpp
        src/data/graphic/Model.cpp
        src/data/Race.cpp
        src/data/System.cpp
        src/data/SkillCategory.cpp
        src/MainWindow.cpp
        src/ViewWindow.cpp
        src/forms/Color.cpp
        src/forms/Button.cpp
        src/Gui.cpp
        src/forms/Form.cpp
        src/forms/InputField.cpp
        src/forms/ImageButton.cpp
        src/pages/BasePage.cpp
        src/pages/SystemPage.cpp
        src/pages/SkillPage.cpp
        src/controllers/GuiController.cpp
        src/controllers/InputFieldContoller.cpp
        src/controllers/CommonController.cpp
        src/controllers/ButtonController.cpp
        src/controllers/FormControllerFactory.cpp
        src/controllers/ImageButtonController.cpp src/pages/RacePage.cpp src/data/storage/StreamWriter.cpp src/data/storage/StreamReader.cpp src/data/DataStorage.cpp src/Toolbar.hpp src/Toolbar.cpp)


target_link_libraries(RollAndPlay ${CONAN_LIBS} GraphicLib)
