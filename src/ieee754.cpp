/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include "ieee754.h"

namespace SCS
{
    bool IEEE754::IsIEEE754(const std::string& value)
    {
        if (value.at(0) != IEEE754_PREFFIX) return false;
        if (value.length() != 9) return false;

        return std::all_of(value.begin() + 1, value.end(), [](char c) {
            return (c >= '0') & (c <= '9') | (c >= 'a') & (c <= 'f') | (c >= 'A') & (c <= 'F');
        });
    }

    std::string IEEE754::ToString(const float value)
    {
        std::stringstream stream;

        stream << std::setfill('0') << std::setw(8) << std::hex << *reinterpret_cast<int*>(const_cast<float*>(&value));
        return IEEE754_PREFFIX + stream.str();
    }

    float IEEE754::ToFloat(const std::string& value)
    {
        std::string       str = value;
        std::stringstream stream;
        int               resValue;

        if (str.at(0) == IEEE754_PREFFIX) str = str.substr(1, str.length() - 1);

        stream << std::hex << str;
        stream >> resValue;

        return *reinterpret_cast<float*>(&resValue);
    }
} // namespace SCS