//
// Created by VerOchka on 22.01.2024.
//

#include "MenuBar.hpp"

namespace Widgets {
    MenuBar::MenuBar(glm::vec2 position, glm::vec2 scale, bool horizontal)
        : Widget(MENU_BAR),
          _position(position),
          _horizontal(horizontal),
          _scale(scale) {}

    void MenuBar::setTransform(glm::vec2 position) {
        _position = position;

        auto elems = _elements;
        _elements.clear();
        for (auto& elem : elems) {
            addElement(elem);
        }
    }

    void MenuBar::setTransform(glm::vec2 position, glm::vec2 scale) {
        _position = position;
        _scale = scale;

        auto elems = _elements;
        _elements.clear();

        for (auto& elem : elems) {
            addElement(elem);
        }
    }

    void MenuBar::setScale(glm::vec2 scale) {
        _scale = scale;

        auto elems = _elements;
        _elements.clear();

        for (auto& elem : elems) {
            addElement(elem);
        }
    }

    void MenuBar::draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                       GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                       GraphicLib::Shaders::ShaderProgram::Ptr pickShader) {
        for (auto& widget : _elements) {
            widget->draw(formShader, textShader, pickShader);
        }
    }

    bool MenuBar::checkSelecting(unsigned int x, unsigned int y) {
        if (canvas == nullptr) {
            return false;
        }

        auto info = canvas->readPixel(x, y);
        auto id = (int)info.ObjectID;

        for (auto& widget : _elements) {
            if (widget->checkId(id)) {
                return true;
            }
        }

        return false;
    }

    void MenuBar::addElement(const Button::Ptr& element) {
        if (canvas != nullptr) {
            element->setCanvas(canvas);
        }

        element->setTransform(_position, _scale);
        if (_horizontal) {
            _position.x += _scale.x + 0.01f;
        } else {
            _position.y -= _scale.y + 0.01f;
        }

        _elements.push_back(element);
    }

    void MenuBar::removeElement(const Button::Ptr& element) {
        auto it = std::find_if(_elements.begin(), _elements.end(), [&](const auto& item) {
            return item == element;
        });

        if (it != _elements.end()) {
            auto elem = *it;
            auto nextElem = *(++it);

            while (it != _elements.end()) {
                nextElem->setTransform(elem->getPosition(), elem->getScale());

                elem = *it;
                nextElem = *(++it);
            }
        }
    }

    void MenuBar::setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) {
        Widget::setCanvas(canvas);

        for (auto& widget : _elements) {
            widget->setCanvas(canvas);
        }
    }

    bool MenuBar::contains(const Button::Ptr& element) {
        auto pos = std::find_if(_elements.begin(), _elements.end(), [&](const auto& item) {
            return item == element;
        });

        return pos != _elements.end();
    }

    const std::vector<Button::Ptr>& MenuBar::getElements() const {
        return _elements;
    }

    void MenuBar::clear() {
        if (_horizontal) {
            _position.x -= (_scale.x + 0.01f) * (float)_elements.size();
        } else {
            _position.y += (_scale.y + 0.01f) * (float)_elements.size();
        }

        _elements.clear();
    }

    glm::vec2 MenuBar::getScale() {
        return _scale;
    }

    glm::vec2 MenuBar::getPosition() {
        return _position;
    }
}    //namespace Widgets
