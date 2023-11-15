#include <iostream>
#include <vector>
#include "include/glad.h"
#include <GLFW/glfw3.h>

std::vector<float> randomColor() {
    std::vector<float> color = {0, 0, 0};
    color[0] = float(std::rand()) / RAND_MAX;
    color[1] = float(std::rand()) / RAND_MAX;
    color[2] = float(std::rand()) / RAND_MAX;

    return color;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // The first two parameters of glViewport set the location of the lower left corner of the window
    // The third and fourth parameter set the width and height of the rendering window in pixels
    printf("window changed!, width: %d, height: %d\n", width, height);
    glViewport(0, 0, 800, 600);
}

void handleInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS) {
        std::cout << "F1 pressed!\n";
        glfwSetWindowShouldClose(window, true);
    }
    else if (glfwGetKey(window, GLFW_KEY_F2) == GLFW_PRESS) {
        // rendering
        std::cout << "F2 pressed!\n";
        std::vector<float> color = randomColor();
        std::cout << color[0] << " " << color[1] << " " << color[2] << std::endl;
        glClearColor(color[0], color[1], color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create a window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLAD before we call any OpenGL functions
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    while(!glfwWindowShouldClose(window)) {
        // User input
        handleInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}