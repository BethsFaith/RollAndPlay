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
            _position.x += _scale.x + _elemOffset;
        } else {
            _position.y -= _scale.y + _elemOffset;
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

    void MenuBar::update() {
        for (const auto& button : _elements) {
            if (button->isPressed()) {
                if (_activeElement.lock() != nullptr) {
                    _activeElement.lock()->setColor(_color);
                }

                _color = button->getColor();

                button->setColor(_selectedItemColor);

                _activeElement = button;
            }
        }
    }

    void MenuBar::clear() {
        if (_activeElement.lock() != nullptr) {
            _activeElement.lock()->setColor(_color);
        }

        if (_horizontal) {
            _position.x -= (_scale.x + _elemOffset) * (float)_elements.size();
        } else {
            _position.y += (_scale.y + _elemOffset) * (float)_elements.size();
        }

        _elements.clear();
    }

    void MenuBar::setSelectedItemColor(const glm::vec3& color) {
        _selectedItemColor = color;
    }

    void MenuBar::setSelectedItemColor(const Styles::Color& color) {
        _selectedItemColor = Styles::getRGB(color);
    }

    glm::vec2 MenuBar::getScale() {
        return _scale;
    }

    glm::vec2 MenuBar::getPosition() {
        return _position;
    }

    const glm::vec3& MenuBar::getSelectedItemColor() const {
        return _selectedItemColor;
    }
}    //namespace Widgets
