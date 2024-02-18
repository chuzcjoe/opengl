#ifndef SHADER_H
#define SHADER_H

#include "include/glad/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "glm.hpp"

class Shader {
private:
    unsigned int m_id;
public:
    Shader(const char* vertexPath, const char* fragmentPath);

    unsigned int getID() const {
        return m_id;
    }

    // use shader program
    void activate();

    void updateColor(const char* name,  std::vector<float>& color);

    void updatePos(const char* name, std::vector<float>& offset);

    void setVec3(const char* name, float v1, float v2, float v3);

    void setVec3(const char* name, glm::vec3& vec3);

    void setMat4(const char* name, const glm::mat4& mat);

    void setInt(const char* name, int i);

    // check compile error
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif