//
// Created by VerOchka on 10.10.2023.
//

#include "Gui.hpp"

GLuint Gui::attachments[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3, GL_COLOR_ATTACHMENT4 };

Gui::Gui() {
    _shader = std::make_shared<Graphic::Shaders::ShaderProgram>
        (R"(..\..\rsrc\shaders\gui.vert)",
         R"(..\..\rsrc\shaders\gui.frag)");
}

void Gui::draw() {
    _shader->use();

    for (auto& button : _buttons) {
        setTransform(button.first->getXOffset(), button.first->getYOffset());
        setColor(Forms::getRGB(button.first->color));

        button.second->draw();
    }
}

void Gui::addButton(const Forms::Button::Ptr button, Graphic::AbstractPrimitive::Ptr primitive) {
    _buttons.emplace_back(button, primitive);

    auto texture = std::make_shared<Graphic::Textures::Texture>("", "");
    texture->setImage(GL_RGB, 3440, 1440, nullptr);

    glTexParameteri(GL_TEXTURE_2D,  GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,  GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    _fbos.emplace_back(Graphic::Buffers::FBO (attachments[attachmentPointer++],
                                             texture->getId()),
                       texture);
}

void Gui::setTransform(float x, float y) {
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::scale(trans, glm::vec3(0.1, 0.1, 0.0f));
    trans = glm::translate(trans, glm::vec3(x, y, 0.0f));

    _shader->set4FloatMat("Transform", glm::value_ptr(trans));
}

void Gui::setColor(float r, float g, float b) {
    _shader->set3FloatVector("Color", r, g, b);
}

void Gui::setColor(glm::vec3 rgb) {
    _shader->set3FloatVector("Color", rgb);
}