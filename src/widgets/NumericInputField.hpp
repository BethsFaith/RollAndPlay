//
// Created by BethsFaith on 26.02.2024.
//

#ifndef INC_1_BIN_NUMERICINPUTFIELD_HPP
#define INC_1_BIN_NUMERICINPUTFIELD_HPP

#include "TextInputField.hpp"

namespace Widgets {
    class NumericInputField : public TextInputField {
    public:
        using Ptr = std::shared_ptr<NumericInputField>;

        explicit NumericInputField(const GraphicLib::Primitives::Rectangle::Ptr& graphicPrimitive,
                                Styles::TextParams inputParams);
        ~NumericInputField() override = default;

        void putToBuffer(const std::string& string) override;
        void putToBuffer(const std::u16string& string) override;
        void putToBuffer(int number);

        int getNumBuffer();
        void putToBuffer(char16_t character) override;
    protected:
        static bool valid(const std::string& string);
        static bool valid(const std::u16string& string);
    };

}    //namespace Widgets

#endif    //INC_1_BIN_NUMERICINPUTFIELD_HPP
