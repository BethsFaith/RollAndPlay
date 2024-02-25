//
// Created by BethsFaith on 09.02.2024.
//

#include "Convert.hpp"

namespace Data::Convert {
    u8string toUTF8(const std::u16string& s)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conv;
        return conv.to_bytes(s);
    }

    u8string toUTF8(const std::u32string& s)
    {
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
        return conv.to_bytes(s);
    }

    std::u16string toUTF16(const u8string& s)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conv;
        return conv.from_bytes(s);
    }

    std::u16string toUTF16(const std::u32string& s)
    {
        std::wstring_convert<std::codecvt_utf16<char32_t>, char32_t> conv;
        std::string bytes = conv.to_bytes(s);
        return std::u16string(reinterpret_cast<const char16_t*>(bytes.c_str()), bytes.length()/sizeof(char16_t));
    }
}