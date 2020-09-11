/*
 * This is an independent project of an individual developer. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */
#include <errormessage.h>
#include <string>

#include <boost/test/unit_test.hpp>

class ErrorSimulator : public SCS::ErrorMessage
{
  public:
    void SimulateError(const std::string& message) const
    {
        SetErrorMessage(message);
    }
};

BOOST_AUTO_TEST_SUITE(TestSuite__ErrorMessage)

std::string msg1 = "Some error message";
std::string msg2 = "Another error message";

BOOST_AUTO_TEST_CASE(Error_InitValue)
{
    ErrorSimulator err;
    BOOST_CHECK_EQUAL(err.GetErrorMessage(), "");
}

BOOST_AUTO_TEST_CASE(Error_SetAndGet)
{
    ErrorSimulator err;

    err.SimulateError(msg1);
    BOOST_CHECK_EQUAL(err.GetErrorMessage(), msg1);
}

BOOST_AUTO_TEST_CASE(Error_DoubleSet)
{
    ErrorSimulator err;

    err.SimulateError(msg1);
    err.SimulateError(msg2);

    BOOST_CHECK_NE(err.GetErrorMessage(), msg1);
}

// TODO Add test for `void SetErrorMessage(const char* format, ...) const;`

BOOST_AUTO_TEST_SUITE_END()