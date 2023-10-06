//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_GLWINDOW_HPP
#define ROLLANDPLAY_GLWINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <wtypes.h>
#include <stdexcept>
#include <glm/glm.hpp>

class GLWindow {
public:
    explicit GLWindow(const char* title);
    GLWindow(const int& width, const int& height, const char* title);

    ~GLWindow();

    void run();

    void setClearColor(const glm::vec4 &clearColor);

    [[nodiscard]] float getDeltaTime() const;

    GLFWwindow *getWindow() const;

protected:
    static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

private:
    void init(const int& width, const int& height, const char* title);
    bool shouldClose();
    void updateDeltaTime();
    void clearColor() const;

    GLFWwindow* _window = nullptr;

    glm::vec4 _clearColor{};

    float _delta_time = 0.0f;	// время между текущим и последним кадрами
    float _last_frame = 0.0f;   // время последнего кадра
};

#endif //ROLLANDPLAY_GLWINDOW_HPP
