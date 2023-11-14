#include <iostream>
#include "include/glad.h"
#include <GLFW/glfw3.h>

int main() {
    std::cout << "OpenGL\n";

    GLFWwindow* window;

    if (!glfwInit()) return -1;

    window = glfwCreateWindow(640, 500, "window", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Couldn't load opengl\n";
        glfwTerminate();
        return -1;
    }

    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
}