/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include "tokenconverter.h"

// Алфавит кодирования
static const char CHARSET[38] = { '\0', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b',
                                  'c',  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                                  'p',  'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '_' };

// Размер алфавита кодирования
const uint8_t CHARSET_LENGTH = sizeof(CHARSET) / sizeof(char);

namespace SCS
{
    uint64_t TokenConverter::Encode(const std::string& text)
    {
        uint64_t token = 0;

        if (text.empty()) return 0;

        if (!IsValidString(text)) throw std::invalid_argument("Input is not a valid token");

        for (size_t i = text.length(); i > 0; --i)
        {
            token = (token * CHARSET_LENGTH) + GetCharIndex(text.at(i - 1));
        }

        return token;
    }

    std::string TokenConverter::Decode(uint64_t token)
    {
        std::string text;

        if (token == 0) return "";

        while (token)
        {
            uint8_t ind = token % CHARSET_LENGTH;
            text += CHARSET[ind];
            token = (token - ind) / CHARSET_LENGTH;
        }

        return text;
    }

    bool TokenConverter::IsValidString(const std::string& text)
    {
        if (text.length() > MAX_LENGTH) return false;

        bool allFromTable = std::all_of(text.begin(), text.end(), [](char ch) {
            return std::any_of(std::begin(CHARSET), std::end(CHARSET), [ch](const char item) {
                return item == ch;
            });
        });

        if (!allFromTable) return false;

        return true;
    }

    uint8_t TokenConverter::GetCharIndex(char letter)
    {
        auto it = std::find(std::begin(CHARSET), std::end(CHARSET), letter);

        if (it == std::end(CHARSET)) return 0;

        return std::distance(CHARSET, it);
    }

} // namespace SCS