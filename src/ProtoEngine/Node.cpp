#include "Node.hpp"

#include "Camera.hpp"
#include "Component.hpp"
#include "Shader.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ProtoEngine {

Node::Node() : parent(nullptr) {}
Node::Node(Node* parent) : parent(parent) {}

glm::mat4 Node::get_model() {
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, position);
    model =
        glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
    model =
        glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
    model =
        glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));
    model = glm::scale(model, scale);

    if (parent != nullptr) {
        return parent->get_model() * model;
    }

    return model;
}

void Node::add_child(Node* child) { children.push_back(child); }

void Node::add_component(Component* component) {
    component->set_node(this);
    components.push_back(component);
}

void Node::set_shader(std::string vs_path, std::string fs_path) {
    shader = new Shader(vs_path.c_str(), fs_path.c_str());
}

void Node::render(Camera& camera) {
    shader->Use();
    GLuint modelLoc = glGetUniformLocation(shader->program(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(get_model()));

    GLuint viewLoc = glGetUniformLocation(shader->program(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.get_view()));

    GLuint projectionLoc =
        glGetUniformLocation(shader->program(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE,
                       glm::value_ptr(camera.get_projection()));

    for (auto& comp : components) {
        comp->render();
    }

    for (auto& child : children) {
        child->render(camera);
    }
}

} // namespace ProtoEngine
