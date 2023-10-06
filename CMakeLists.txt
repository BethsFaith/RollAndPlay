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
        src/GLWindow.cpp)

target_link_libraries(RollAndPlay ${CONAN_LIBS})
