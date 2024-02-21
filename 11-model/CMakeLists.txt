cmake_minimum_required(VERSION 3.0.0)
project(opengl1 VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(assimp REQUIRED)

include_directories(glad)
include_directories(utils)
include_directories(stb)
include_directories(glm)
include_directories(mesh)
include_directories(model)
include_directories(${ASSIMP_INCLUDE_DIRS})
add_definitions(-D__APPLE__)

add_executable(myOpenGL src/main.cpp 
                        glad/src/glad.c
                        utils/shader.cpp
                        utils/camera.cpp)


link_directories(assimp/bin)
target_link_libraries(myOpenGL 
                        glfw
                        OpenGL::GL
                        ${ASSIMP_LIBRARIES}
                        )