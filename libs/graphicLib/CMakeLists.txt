cmake_minimum_required(VERSION 3.25)
project(GraphicLib)

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

add_library(GraphicLib
        libs/stb_image.cpp
        src/primitives/Primitive.cpp
        src/buffers/Vertex.cpp
        src/buffers/Vbo.cpp
        src/buffers/VboT.cpp
        src/buffers/Vao.cpp
        src/buffers/RaiiBuffer.cpp
        src/buffers/Ebo.cpp
        src/primitives/Rectangle.cpp
        src/shaders/ShaderProgram.cpp
        src/buffers/Fbo.cpp
        src/textures/Loader.cpp
        src/textures/Texture.cpp
        src/Text.cpp
        )

target_link_libraries(GraphicLib ${CONAN_LIBS})
target_include_directories(GraphicLib PUBLIC headers)
