#pragma once

// light properties
namespace DirLight {
    glm::vec3 direction(-0.2f, -1.0f, -0.3f);

    glm::vec3 ambient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
}

namespace PointLight {
    glm::vec3 position(1.2f, 1.0f, 2.0f);

    glm::vec3 ambient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);

    float constant = 1.0f;
    // like radius
    float linear = 0.09f;
    // like intensity
    float quadratic = 0.032f;
}

namespace SpotLight {
    glm::vec3 position(1.2f, 1.0f, 2.0f);
    glm::vec3 direction(-0.2f, -1.0f, -0.3f);

    glm::vec3 ambient = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);

    float constant = 1.0f;
    // like radius
    float linear = 0.09f;
    // like intensity
    float quadratic = 0.032f;
}