#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "include/glad.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include <iostream>

#define CLIP(value, minVal, maxVal) ((value) < (minVal) ? (minVal) : ((value) > (maxVal) ? (maxVal) : (value)))

enum CameraMove {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera {
public:
    // camera attribute
    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_worldup;

    // euler angle
    float m_yaw; // around y-axis
    float m_pitch; // around x-axis

    // camera options
    float m_speed;
    float m_sensitivity;
    float m_zoom;

    Camera(glm::vec3& position, glm::vec3& up, float yaw, float pitch);
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    glm::mat4 GetViewMatrix();

    void ProcessKeyPressed(CameraMove direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch);
    void ProcessMouseScroll(float yoffset);

private:
    void updateCameraVectors();

};

#endif