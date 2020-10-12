/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include <color.h>

#include <boost/test/floating_point_comparison.hpp> // BOOST_CHECK_CLOSE
#include <boost/test/unit_test.hpp>

struct FixtureColor
{
    FixtureColor() : color()
    {
    }

    ~FixtureColor() = default;

    float fRLinear = 64.0f / 255.0f;
    float fGLinear = 128.0f / 255.0f;
    float fBLinear = 255.0f / 255.0f;

    float fRQuadratic = powf(64.0f / 255.0f, 2);
    float fGQuadratic = powf(128.0f / 255.0f, 2);
    float fBQuadratic = powf(255.0f / 255.0f, 2);

    uint8_t iR = 64;
    uint8_t iG = 128;
    uint8_t iB = 255;

    SCS::Color color;
};

BOOST_FIXTURE_TEST_SUITE(TestSuite__Color, FixtureColor)

double tolerance = 0.1;

BOOST_AUTO_TEST_CASE(Color__ToSCS_Linear)
{
    SCS::Color::RGB structRGB(iR, iG, iB);
    SCS::Color::SCS scsRes = color.ToSCS(structRGB, SCS::Color::Linear);

    BOOST_CHECK_CLOSE(scsRes.r, fRLinear, tolerance);
    BOOST_CHECK_CLOSE(scsRes.g, fGLinear, tolerance);
    BOOST_CHECK_CLOSE(scsRes.b, fBLinear, tolerance);
}

BOOST_AUTO_TEST_CASE(Color__ToRGB_Linear)
{
    SCS::Color::SCS structSCS(fRLinear, fGLinear, fBLinear);
    SCS::Color::RGB rgbRes = color.ToRGB(structSCS, SCS::Color::Linear);

    BOOST_CHECK_EQUAL(rgbRes.r, iR);
    BOOST_CHECK_EQUAL(rgbRes.g, iG);
    BOOST_CHECK_EQUAL(rgbRes.b, iB);
}

BOOST_AUTO_TEST_CASE(Color__ToSCS_Quadratic)
{
    SCS::Color::RGB structRGB(iR, iG, iB);
    SCS::Color::SCS scsRes = color.ToSCS(structRGB, SCS::Color::Quadratic);

    BOOST_CHECK_CLOSE(scsRes.r, fRQuadratic, tolerance);
    BOOST_CHECK_CLOSE(scsRes.g, fGQuadratic, tolerance);
    BOOST_CHECK_CLOSE(scsRes.b, fBQuadratic, tolerance);
}

BOOST_AUTO_TEST_CASE(Color__ToRGB_Quadratic)
{
    SCS::Color::SCS structSCS(fRQuadratic, fGQuadratic, fBQuadratic);
    SCS::Color::RGB rgbRes = color.ToRGB(structSCS, SCS::Color::Quadratic);

    BOOST_CHECK_EQUAL(rgbRes.r, iR);
    BOOST_CHECK_EQUAL(rgbRes.g, iG);
    BOOST_CHECK_EQUAL(rgbRes.b, iB);
}

BOOST_AUTO_TEST_SUITE_END()