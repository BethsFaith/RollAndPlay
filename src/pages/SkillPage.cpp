//
// Created by VerOchka on 30.10.2023.
//

#include "SkillPage.hpp"

namespace Pages {
    SkillPage::SkillPage(GraphicLib::PickableTexture::Ptr canvas) : BasePage(std::move(canvas)) {
        SkillPage::update();
    }

    void SkillPage::update() {
        BasePage::update();

        switch (_currentTag) {
            case START:
                toStart();
                break;
            case VIEW:
                toView();
                break;
        }
    }

    void SkillPage::toStart() {
        GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);

        //кнопочки
        auto button = std::make_shared<Forms::Button>(rectangle);
        button->init({0.1, 0.1f, 0.0f}, {-8.5, 7.0}, {
                .content =  u"Создать категорию",
                .x = 0.06,
                .y = 0.15
        }, Forms::GRAY);
        button->setPressCallback([&]() {
            this->_currentTag = StateTag::VIEW;
            this->update();
        });

        addButton(button);
    }

    void SkillPage::toView() {
        GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);

        //кнопочки
        auto button = std::make_shared<Forms::Button>(rectangle);
        button->init({0.1, 0.1f, 0.0f}, {-8.5, 7.0}, {
                .content = u"Сохранить",
                .x = 0.055,
                .y = 0.15
        },Forms::GRAY);
        button->setPressCallback([&]() {
            this->_currentTag = StateTag::START;
            this->update();
        });
        addButton(button);

        auto nameButton = std::make_shared<Forms::InputField>(rectangle,
                                                              Forms::Text{
                                                                      .x = 0.055,
                                                                      .y = 0.30,
                                                                      .color = Forms::Color::BLACK
                                                              });
        nameButton->init({0.7f, 0.1f, 0.0f}, {-0.79, 4.0}, {
                .content = u"Название",
                .x = 0.055,
                .y = 0.25
        }, Forms::Color::LIGHT_GRAY);
        addButton(nameButton);

        auto rectangle2 =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = true,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle2->bindData(GL_STATIC_DRAW);

        auto coverButton = std::make_shared<Forms::ImageButton>(rectangle2);
        coverButton->init({0.2f, 0.3f, 0.0f}, {-4, 0.0}, {
                .content = u"Обложка",
                .x = 0.055,
                .y = 0.40
        }, R"(..\..\rsrc\textures\no-img.jpg)", 0);

        auto attachCoverButton = std::make_shared<Forms::InputField>(rectangle,
                                                                     Forms::Text{
                                                                             .x = 0.055,
                                                                             .y = 0.65,
                                                                             .color = Forms::Color::BLACK
                                                                     });
        attachCoverButton->init({0.7f, 0.1f, 0.0f}, {-0.79, -3.0}, {
                .content = u"Путь к изображению : ",
                .x = 0.055,
                .y = 0.6
        }, Forms::Color::LIGHT_GRAY);
        attachCoverButton->setPressCallback([attachCoverButton, coverButton, this](){
            coverButton->setImage(attachCoverButton->getU8Buf());
        });

        addButton(coverButton);
        addButton(attachCoverButton);
    }
}