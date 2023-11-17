#ifndef SHADER_H
#define SHADER_H

#include "include/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Shader {
private:
    unsigned int m_id;
public:
    Shader(const char* vertexPath, const char* fragmentPath);

    // use shader program
    void activate();

    void updateColor(const char* name,  std::vector<float>& color);

    void updatePos(const char* name, std::vector<float>& offset);

    // check compile error
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif