/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include <hexcodec.h>
#include <string>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuite__HexCodec)

std::string msgRaw = "Hello";
std::string msgHex = "48656C6C6F";

BOOST_AUTO_TEST_CASE(HexCodec__ConstructRaw)
{
    SCS::HexCodec hc(msgRaw, false);
    BOOST_CHECK_EQUAL(hc.GetHex(), msgHex);
}

BOOST_AUTO_TEST_CASE(HexCodec__ConstructHex)
{
    SCS::HexCodec hc(msgHex, true);
    BOOST_CHECK_EQUAL(hc.GetRaw(), msgRaw);
}

BOOST_AUTO_TEST_CASE(HexCodec__RawToHex)
{
    SCS::HexCodec hc;

    hc.SetRaw(msgRaw);
    BOOST_CHECK_EQUAL(hc.GetHex(), msgHex);
}

BOOST_AUTO_TEST_CASE(HexCodec__HexToRaw)
{
    SCS::HexCodec hc;

    hc.SetHex(msgHex);
    BOOST_CHECK_EQUAL(hc.GetRaw(), msgRaw);
}

BOOST_AUTO_TEST_SUITE_END()