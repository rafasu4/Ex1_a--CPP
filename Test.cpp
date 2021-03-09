#include "doctest.h"
#include "snowman.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Good snowman code") {
    //test unit for each part
    CHECK(ariel::snowman(11111111) == string("_===_(.,.)<( : )>( : )"));
    CHECK(ariel::snowman(22222222) == string("___.....\\(o.o)/(] [)(\" \")"));
    CHECK(ariel::snowman(33333333) == string("_/_\\(O_O)/(> <)\\(___)"));
    CHECK(ariel::snowman(44444444) == string("___(_*_)(- -)(   )(   )"));
    //test combination of parts
    CHECK(ariel::snowman(12344321) == string("_===_(O.-)(] [)\\( : )"));
    CHECK(ariel::snowman(43211234) == string("___(_*_)(o_.)/<(> <)(   )"));
    CHECK(ariel::snowman(11114411) == string("_===_(.,.)( : )( : )"));
    CHECK(ariel::snowman(33232124) == string("_/_\\\\(o_O)(] [)>(   )"));
    CHECK(ariel::snowman(23412341) == string("___.....\\(-_.)(   )\\( : )"));
    CHECK(ariel::snowman(22334411) == string("___.....(O.O)( : )( : )"));
    CHECK(ariel::snowman(43211234) == string("___(_*_)(o_.)/<(> <)(   )"));
    CHECK(ariel::snowman(31412111) == string("_/_\\\\(-,.)( : )>( : )"));
    CHECK(ariel::snowman(22233341) == string("___.....(o.O)/(   )\\( : )"));
    CHECK(ariel::snowman(14234123) == string("_===_(o O)(] [)>(___)"));
}

TEST_CASE("Bad snowman code") {
            CHECK_THROWS(ariel::snowman(555));
            CHECK_THROWS(ariel::snowman(123456789));
            CHECK_THROWS(ariel::snowman('a'));
            CHECK_THROWS(ariel::snowman(01010101));
            CHECK_THROWS(ariel::snowman(-12345678));
            CHECK_THROWS(ariel::snowman(-1-2-3));
    /* Add more checks here */
}


