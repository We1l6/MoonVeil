#include <catch2/catch_test_macros.hpp>
#include "calculator.h"


Calculator calculator;

TEST_CASE( "Calculator are computed", "[calculator]" ) {
    REQUIRE(calculator.add(4, 6) == 10);
    REQUIRE(calculator.div(12, 6) == 2);
    REQUIRE(calculator.mod(4, 2) == 16);
    REQUIRE(calculator.mul(4, 6) == 24);
    REQUIRE(calculator.sub(12, 6) == 6);
}
