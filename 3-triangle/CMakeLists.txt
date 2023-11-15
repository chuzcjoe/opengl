cmake_minimum_required(VERSION 3.0.0)
project(opengl1 VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

include_directories(glad)
add_executable(myOpenGL src/main.cpp 
                        glad/src/glad.c)

add_executable(exercise1 src/exercise1.cpp 
                        glad/src/glad.c)

add_executable(exercise2 src/exercise2.cpp 
                        glad/src/glad.c)  

add_executable(exercise3 src/exercise3.cpp 
                        glad/src/glad.c) 

target_link_libraries(myOpenGL 
                        glfw
                        OpenGL::GL)

target_link_libraries(exercise1 
                        glfw
                        OpenGL::GL)

target_link_libraries(exercise2 
                        glfw
                        OpenGL::GL)

target_link_libraries(exercise3 
                        glfw
                        OpenGL::GL)