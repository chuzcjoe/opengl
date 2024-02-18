#include "camera.h"

Camera::Camera(glm::vec3& position, glm::vec3& up, float yaw, float pitch) {
    m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    m_speed = 2.5f;
    m_sensitivity = 0.1f;
    m_zoom = 45.0f;
    m_position = position;
    m_worldup = up;
    m_yaw = yaw;
    m_pitch = pitch;
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) {
    m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    m_speed = 2.5f;
    m_sensitivity = 0.1f;
    m_zoom = 45.0f;
    m_position = glm::vec3(posX, posY, posZ);
    m_worldup = glm::vec3(upX, upY, upZ);
    m_yaw = yaw;
    m_pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::ProcessKeyPressed(CameraMove direction, float deltaTime) {
    float v = m_speed * deltaTime;
    switch (direction) {
        case FORWARD:
            m_position += m_front * v;
            break;
        case BACKWARD:
            m_position -= m_front * v;
            break;
        case LEFT:
            m_position -= m_right * v;
            break;
        case RIGHT:
            m_position += m_right * v;
            break;
        default:
            break;
    }
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch) {
    xoffset *= m_sensitivity;
    yoffset *= m_sensitivity;

    m_yaw += xoffset;
    m_pitch += yoffset;

    if (constrainPitch)
        m_pitch = CLIP(m_pitch, -89.0f, 89.0f);
    
    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset) {
    m_zoom -= yoffset;
    m_zoom = CLIP(m_zoom, 1.0f, 45.0f);
}

// Calculate new front vector from Euler angles
void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = std::cos(glm::radians(m_yaw) * std::cos(glm::radians(m_pitch)));
    front.y = std::sin(glm::radians(m_pitch));
    front.z = std::sin(glm::radians(m_yaw) * std::cos(glm::radians(m_pitch)));
    
    // update front
    m_front = glm::normalize(front);

    // update right and up vectors
    m_right = glm::normalize(glm::cross(m_front, m_worldup));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}