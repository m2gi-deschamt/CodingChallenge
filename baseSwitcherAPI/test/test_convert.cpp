#include <drogon/drogon_test.h>
#include "../src/convert.h"
#include <string>

DROGON_TEST(ConvertTest){
    std::string value = "1001";
    int base2 = 2;
    int base10 = 10;
    std::string result = from_X_to_10(value,base2);

    CHECK(result == "9");

    result = from_10_to_X(result,base2);

    CHECK(result == "1001");
}

DROGON_TEST(ConvertTestFromXToY){
    std::string result = from_X_to_Y("3011", 4, 5);
    CHECK(result == "1242");
}