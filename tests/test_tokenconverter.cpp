/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include <tokenconverter.h>
#include <string>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuite__TokenConverter)

std::string sampleText  = "venezia";
uint64_t    sampleToken = 0x81461CB02;

BOOST_AUTO_TEST_CASE(TokenConverter__Encode)
{
    BOOST_CHECK_EQUAL(SCS::TokenConverter::Encode(sampleText), sampleToken);
}

BOOST_AUTO_TEST_CASE(TokenConverter__Decode)
{
    BOOST_CHECK_EQUAL(SCS::TokenConverter::Decode(sampleToken), sampleText);
}

BOOST_AUTO_TEST_SUITE_END()