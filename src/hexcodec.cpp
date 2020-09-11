/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include "hexcodec.h"

namespace SCS
{
    HexCodec::HexCodec() : m_value("")
    {
    }

    HexCodec::HexCodec(const std::string& value, bool isHex /*= false*/)
    {
        if (isHex)
            SetHex(value);
        else
            SetRaw(value);
    }

    std::string HexCodec::GetRaw()
    {
        return m_value;
    }

    void HexCodec::SetRaw(const std::string& value)
    {
        m_value = value;
    }

    std::string HexCodec::GetHex()
    {
        return boost::algorithm::hex(m_value);
    }

    void HexCodec::SetHex(const std::string& value)
    {
        try
        {
            m_value = boost::algorithm::unhex(value);
        }
        catch (const boost::algorithm::not_enough_input&)
        {
            SetErrorMessage("Invalid hex sequence: input does not contain enough hex digits");
        }
        catch (const boost::algorithm::non_hex_input&)
        {
            SetErrorMessage("Invalid hex sequence: input contains non-hexadecimal characters");
        }
    }

    HexCodec::operator std::string()
    {
        return GetRaw();
    }
} // namespace SCS