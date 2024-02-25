//
// Created by BethsFaith on 09.02.2024.
//

#ifndef INC_1_BIN_CONVERT_HPP
#define INC_1_BIN_CONVERT_HPP

#include <iostream>
#include <codecvt>

namespace Data::Convert {
    typedef std::string u8string;

    u8string toUTF8(const std::u16string& s);

    u8string toUTF8(const std::u32string& s);

    std::u16string toUTF16(const u8string& s);

    std::u16string toUTF16(const std::u32string& s);
}
#endif    //INC_1_BIN_CONVERT_HPP
