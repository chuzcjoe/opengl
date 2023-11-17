cmake_minimum_required(VERSION 3.0.0)
project(opengl1 VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

include_directories(glad)
include_directories(shader)
add_executable(myOpenGL src/main.cpp 
                        glad/src/glad.c
                        shader/shader.cpp)

target_link_libraries(myOpenGL 
                        glfw
                        OpenGL::GL)