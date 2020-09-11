/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include <ieee754.h>
#include <string>

#include <boost/test/floating_point_comparison.hpp> // BOOST_CHECK_CLOSE
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuite__IEEE754)

double      tolerance  = 0.1;
float       floatValue = 0.1234f;
std::string strValue   = "&3dfcb924";

BOOST_AUTO_TEST_CASE(IEEE754__IsIEEE754)
{
    BOOST_CHECK(SCS::IEEE754::IsIEEE754(strValue));
}

BOOST_AUTO_TEST_CASE(IEEE754__ToFloat)
{
    float value = SCS::IEEE754::ToFloat(strValue);
    BOOST_CHECK_CLOSE(value, floatValue, tolerance);
}

BOOST_AUTO_TEST_CASE(IEEE754__ToString)
{
    std::string value = SCS::IEEE754::ToString(floatValue);
    BOOST_CHECK_EQUAL(value, strValue);
}

BOOST_AUTO_TEST_SUITE_END()