/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include "color.h"

namespace SCS
{
    Color::RGB::RGB(const uint8_t r, const uint8_t g, const uint8_t b) : r(r), g(g), b(b)
    {
    }

    Color::SCS::SCS(const float r, const float g, const float b) :
        r(::SCS::clamp(r, 0.0f, 1.0f)), g(::SCS::clamp(g, 0.0f, 1.0f)), b(::SCS::clamp(b, 0.0f, 1.0f))
    {
    }

    Color::RGB Color::ToRGB(const SCS& color, const ETransform transform /* = Quadratic*/)
    {
        return RGB { Transform(color.r, transform), Transform(color.g, transform), Transform(color.b, transform) };
    }

    Color::SCS Color::ToSCS(const RGB& color, const ETransform transform /* = Quadratic*/)
    {
        return SCS { Transform(color.r, transform), Transform(color.g, transform), Transform(color.b, transform) };
    }

    uint8_t Color::Transform(const float value, const ETransform transform /* = Quadratic*/)
    {
        switch (transform)
        {
            case Color::Linear:
                return static_cast<uint8_t>(::SCS::clamp(value, 0.0f, 1.0f) * 255);
            case Color::Quadratic:
            default:
                return static_cast<uint8_t>(sqrtf(::SCS::clamp(value, 0.0f, 1.0f)) * 255);
        }
    }

    float Color::Transform(const uint8_t value, const ETransform transform /* = Quadratic*/)
    {
        switch (transform)
        {
            case Color::Linear:
                return static_cast<float>(value) / 255;
            case Color::Quadratic:
            default:
                return powf(static_cast<float>(value) / 255, 2);
        }
    }
} // namespace SCS