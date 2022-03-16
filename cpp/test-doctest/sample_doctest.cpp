#include "ApprovalTests.hpp"
#include "doctest/doctest.h"


#include "sample.h"

using namespace std;

TEST_CASE ("LeapYear") {
    SUBCASE("Typical case: every 4 years") {
        CHECK(isLeapYear(2000));
        CHECK(isLeapYear(2001) == false);
        CHECK(isLeapYear(2002) == false);
        CHECK(isLeapYear(2003) == false);
        CHECK(isLeapYear(2004));
        CHECK(isLeapYear(0));
    }
    SUBCASE("Atypical leap year") {
        CHECK(isLeapYear(2000));
        CHECK(isLeapYear(2800));
        CHECK(isLeapYear(2400));
    }
    SUBCASE("Atypical common year (not dividable by 400)") {
        CHECK(isLeapYear(1800) == false);
        CHECK(isLeapYear(1900) == false);
        CHECK(isLeapYear(2300) == false);
        CHECK(isLeapYear(300) == false);
        CHECK(isLeapYear(-100) == false);
    }
}

TEST_CASE ("isLeapYear") {
    SUBCASE("divisible by 4") {
        REQUIRE(isLeapYear(1996) == true);
        REQUIRE(isLeapYear(2001) == false);
    }
    SUBCASE("no leap year when divisible by 100") {
        REQUIRE(isLeapYear(1900) == false);
    }
    SUBCASE("leap year when divisible by 400") {
        REQUIRE(isLeapYear(2000) == true);
    }
}

TEST_CASE ("Leap_Years") {
    SUBCASE("checking numbers") {
        for (int i = 0; i < 2400; ++i) {
            if (i % 400 == 0) {
                REQUIRE(true == isLeapYear(i));
            } else if (i % 100 == 0) {
                REQUIRE(false == isLeapYear(i));
            } else if (i % 4 == 0) {
                REQUIRE(true == isLeapYear(i));
            } else {
                REQUIRE(false == isLeapYear(i));
            }
        }
    }
}


TEST_CASE ("FizzBuzz all") {
    SUBCASE("Loop from 0 to 1155 (3*5*7*11)") {

        int i = 1;

        while (i <= 1155) {
            if ((i % 3 == 0) && (i % 5 == 0) && (i % 7 == 0) && (i % 11 == 0)) {
                CHECK(fizzBuzz(i) == "FizzBuzzWhizzBang");

                CHECK(i == 1155);
            } else if ((i % 3 == 0) && (i % 5 == 0) && (i % 7 == 0)) {
                CHECK(fizzBuzz(i) == "FizzBuzzWhizz");
            } else if ((i % 3 == 0) && (i % 5 == 0) && (i % 11 == 0)) {
                CHECK(fizzBuzz(i) == "FizzBuzzBang");
            } else if ((i % 3 == 0) && (i % 7 == 0) && (i % 11 == 0)) {
                CHECK(fizzBuzz(i) == "FizzWhizzBang");
            } else if ((i % 5 == 0) && (i % 7 == 0) && (i % 11 == 0)) {
                CHECK(fizzBuzz(i) == "BuzzWhizzBang");
            } else if ((i % 7 == 0) && (i % 11 == 0)) {
                CHECK(fizzBuzz(i) == "WhizzBang");
            } else if ((i % 5 == 0) && (i % 11 == 0)) {
                CHECK(fizzBuzz(i) == "BuzzBang");
            } else if ((i % 5 == 0) && (i % 7 == 0)) {
                CHECK(fizzBuzz(i) == "BuzzWhizz");
            } else if ((i % 3 == 0) && (i % 5 == 0)) {
                CHECK(fizzBuzz(i) == "FizzBuzz");
            } else if ((i % 3 == 0) && (i % 7 == 0)) {
                CHECK(fizzBuzz(i) == "FizzWhizz");
            } else if ((i % 3 == 0) && (i % 11 == 0)) {
                CHECK(fizzBuzz(i) == "FizzBang");
            } else if (i % 3 == 0) {
                CHECK(fizzBuzz(i) == "Fizz");
            } else if (i % 5 == 0) {
                CHECK(fizzBuzz(i) == "Buzz");
            } else if (i % 7 == 0) {
                CHECK(fizzBuzz(i) == "Whizz");
            } else if (i % 11 == 0) {
                CHECK(fizzBuzz(i) == "Bang");
            } else {
                CHECK(fizzBuzz(i) == to_string(i));
            }

            i++;
        }
    }
}

TEST_CASE("FizzBuzzWhizzBang") {
    SUBCASE("only divisible by 3") {
        for (int i = 1; i <= 100; i += 1) {
            if (i % 3 != 0) continue;
            if (i % 5 == 0) continue;
            if (i % 7 == 0) continue;
            if (i % 11 == 0) continue;
            REQUIRE(fizzBuzz(i) == "Fizz");
        }
    }
    SUBCASE("only divisible by 5") {
        for (int i = 1; i <= 100; i += 1) {
            if (i % 3 == 0) continue;
            if (i % 5 != 0) continue;
            if (i % 7 == 0) continue;
            if (i % 11 == 0) continue;
            REQUIRE(fizzBuzz(i) == "Buzz");
        }
    }
    SUBCASE("only divisible by 7") {
        for (int i = 1; i <= 100; i += 1) {
            if (i % 3 == 0) continue;
            if (i % 5 == 0) continue;
            if (i % 7 != 0) continue;
            if (i % 11 == 0) continue;
            REQUIRE(fizzBuzz(i) == "Whizz");
        }
    }
    SUBCASE("only divisible by 11") {
        for (int i = 1; i <= 100; i += 1) {
            if (i % 3 == 0) continue;
            if (i % 5 == 0) continue;
            if (i % 7 == 0) continue;
            if (i % 11 != 0) continue;
            REQUIRE(fizzBuzz(i) == "Bang");
        }
    }
    SUBCASE("not divisible by 3, 5, 7, 11") {
        for (int i = 1; i <= 100; i += 1) {
            if (i % 3 == 0) continue;
            if (i % 5 == 0) continue;
            if (i % 7 == 0) continue;
            if (i % 11 == 0) continue;
            REQUIRE(fizzBuzz(i) == to_string(i));
        }
    }
}

TEST_CASE ("fizzBuzz") {

    // Multiples of 3 are “Fizz”
    // Multiples of 5 are “Buzz”
    // Multiples of 7 are “Whizz”
    // Multiples of 11 are “Bang”
    SUBCASE("Test result of fizzBuzz with expected values") {
        for (int i = 1; i <= 100; i += 1) {
            CAPTURE(i);
            if (i % 3 == 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == "Fizz");
            if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == to_string(i));
            if (i % 3 == 0 && i % 5 == 0 && i % 7 != 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == "FizzBuzz");
            if (i % 3 != 0 && i % 5 == 0 && i % 7 != 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == "Buzz");
            if (i % 3 == 0 && i % 5 != 0 && i % 7 == 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == "FizzWhizz");
            if (i % 3 != 0 && i % 5 != 0 && i % 7 == 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == "Whizz");
            if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == "FizzBuzzWhizz");
            if (i % 3 != 0 && i % 5 == 0 && i % 7 == 0 && i % 11 != 0) REQUIRE(fizzBuzz(i) == "BuzzWhizz");
            if (i % 3 == 0 && i % 5 != 0 && i % 7 != 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "FizzBang");
            if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "Bang");
            if (i % 3 == 0 && i % 5 == 0 && i % 7 != 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "FizzBuzzBang");
            if (i % 3 != 0 && i % 5 == 0 && i % 7 != 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "BuzzBang");
            if (i % 3 == 0 && i % 5 != 0 && i % 7 == 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "FizzWhizzBang");
            if (i % 3 != 0 && i % 5 != 0 && i % 7 == 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "WhizzBang");
            if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "FizzBuzzWhizzBang");
            if (i % 3 != 0 && i % 5 == 0 && i % 7 == 0 && i % 11 == 0) REQUIRE(fizzBuzz(i) == "BuzzWhizzBang");
        }
    }

    SUBCASE("Result should be FizzBuzzWhizzBang") {
        REQUIRE(fizzBuzz(1*(3*5*7*11)) == "FizzBuzzWhizzBang");
        REQUIRE(fizzBuzz(2*(3*5*7*11)) == "FizzBuzzWhizzBang");
        REQUIRE(fizzBuzz(3*(3*5*7*11)) == "FizzBuzzWhizzBang");
    }
}


TEST_CASE ("FizzBuzz") {
    SUBCASE("checking 0 to 200") {
        for (int i = 1; i < 200; ++i) {
            string mytarget;
            // 3, 6,...       -> Fizz
            // 5,10,...       -> Buzz
            // 7,14,...       -> Whizz
            //11,22,...       -> Bang
            //15,30,...       -> FizzBuzz
            //105,210...      -> FizzBuzzWhizz
            if (i % 3 == 0) { mytarget = mytarget + "Fizz"; }
            if (i % 5 == 0) { mytarget = mytarget + "Buzz"; }
            if (i % 7 == 0) { mytarget = mytarget + "Whizz"; }
            if (i % 11 == 0) { mytarget = mytarget + "Bang"; }

            //if no special case got hit - set the number
            if (mytarget.empty()) {
                mytarget = to_string(i);
            }
            REQUIRE(mytarget == fizzBuzz(i));
        }

    }
    SUBCASE("checking FizzBuzzWhizzBang") {
        for (int i = 0; i < 1156; i++) {
            if (i % 3 == 0) {
                if (i % 5 == 0) {
                    if (i % 7 == 0) {
                        if (i % 11 == 0) { //1155
                            REQUIRE("FizzBuzzWhizzBang" == fizzBuzz(i));
                        }
                    }
                }
            }
        }
    }

}


TEST_CASE ("Closest to Zero") {
    SUBCASE("0, 1, 2") {
        vector<int> v1 = {0, 1, 2};
        CHECK(closestToZero(&v1) == 0);
    }

    SUBCASE("1, 1, 1") {
        vector<int> v1 = {1, 1, 1};
        CHECK(closestToZero(&v1) == 1);
    }

    SUBCASE("-1, 1, 2") {
        vector<int> v1 = {-1, 1, 2};
        CHECK(closestToZero(&v1) == 1);
    }

    SUBCASE("-1, 2, 3") {
        vector<int> v1 = {-1, 2, 3};
        CHECK(closestToZero(&v1) == -1);
    }

    SUBCASE("3, 2, -1") {
        vector<int> v1 = {3, 2, -1};
        CHECK(closestToZero(&v1) == -1);
    }
}


TEST_CASE ("closestToZero(vector<int>*)") {
    SUBCASE("nullptr or empty throws") {
        vector<int> sample{};
        REQUIRE_THROWS_AS(closestToZero(nullptr), invalid_argument);
        REQUIRE_THROWS_AS(closestToZero(&sample), invalid_argument);
    }
    SUBCASE("increasing") {
        vector<int> sample{1,2,3,4};
        REQUIRE(closestToZero(&sample) == 1);
    }
    SUBCASE("decreasing") {
        vector<int> sample{4,3,2,1};
        REQUIRE(closestToZero(&sample) == 1);
    }
    SUBCASE("all the same (positive)") {
        vector<int> sample{2,2,2,2};
        REQUIRE(closestToZero(&sample) == 2);
    }
    SUBCASE("all the same (negative)") {
        vector<int> sample{-2,-2,-2,-2};
        REQUIRE(closestToZero(&sample) == -2);
    }
    SUBCASE("tie (positive wins)") {
        vector<int> sample{-2,-2,+2,+2};
        REQUIRE(closestToZero(&sample) == 2);
    }
    SUBCASE("") {
        vector<int> sample{-4,-2,+2,+2};
        REQUIRE(closestToZero(&sample) == 2);
    }
    SUBCASE("min/max of int: max wins") {
        vector<int> sample{numeric_limits<int>::min(), numeric_limits<int>::max()};
        REQUIRE(closestToZero(&sample) == numeric_limits<int>::max());
    }
}


TEST_CASE ("Closest to Zero vector") {
    SUBCASE("vector 7 3 9") {
        std::vector<int> vec739;
        vec739.push_back(7);
        vec739.push_back(3);
        vec739.push_back(9);
        REQUIRE(3 == closestToZero(&vec739));
    }

    SUBCASE("vector 7 -2 9") {
        std::vector<int> vec7_29;
        vec7_29.push_back(7);
        vec7_29.push_back(-2);
        vec7_29.push_back(9);
        REQUIRE(-2 == closestToZero(&vec7_29));
    }
}

