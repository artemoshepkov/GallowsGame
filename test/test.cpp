#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
// in one cpp file
#include "catch.hpp"
#include <libgallows/functions.h>
#include <string>

TEST_CASE("CheckLetter")
{
    std::string word = "ANTILOPA";
    int WORDSIZE = 8;
    int verno[7] = {0, 8, 11, 13, 14, 15, 18};
    int neverno[24] = {1,  2,  3,  4,  5,  6,  7,  9,  10, 12, 16, 17,
                       19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

    for (int i = 0; i < 7; i++)
        REQUIRE(CheckLetter(word, WORDSIZE, verno[i]) == 1);
    for (int i = 0; i < 24; i++)
        REQUIRE(CheckLetter(word, WORDSIZE, neverno[i]) == 0);
}

TEST_CASE("SumMistakes")
{
    std::string word = "ANTILOPA";
    int WORDSIZE = 8;
    int NUMBERLETTERS = 31;
    bool Markers1[NUMBERLETTERS]
            = {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,
               0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    REQUIRE(SumMistakes(Markers1, word, NUMBERLETTERS, WORDSIZE) == -1);

    bool Markers2[NUMBERLETTERS]
            = {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,
               0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    REQUIRE(SumMistakes(Markers2, word, NUMBERLETTERS, WORDSIZE) == 0);

    bool Markers3[NUMBERLETTERS]
            = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,
               0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    REQUIRE(SumMistakes(Markers3, word, NUMBERLETTERS, WORDSIZE) == 1);

    bool Markers4[NUMBERLETTERS]
            = {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
               1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1};
    REQUIRE(SumMistakes(Markers4, word, NUMBERLETTERS, WORDSIZE) == 5);
}
TEST_CASE("ManYouRight")
{
    std::string word = "ANTILOPA";
    int WORDSIZE = 8;
    int NUMBERLETTERS = 31;
    bool Markers0[NUMBERLETTERS]
            = {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,
               0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    REQUIRE(ManYouRight(Markers0, word, NUMBERLETTERS, WORDSIZE) == 7);

    bool Markers1[NUMBERLETTERS]
            = {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,
               0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    REQUIRE(ManYouRight(Markers1, word, NUMBERLETTERS, WORDSIZE) == 6);

    bool Markers2[NUMBERLETTERS]
            = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,
               0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    REQUIRE(ManYouRight(Markers2, word, NUMBERLETTERS, WORDSIZE) == 5);

    bool Markers3[NUMBERLETTERS]
            = {1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
               0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    REQUIRE(ManYouRight(Markers3, word, NUMBERLETTERS, WORDSIZE) == 4);

    bool Markers4[NUMBERLETTERS]
            = {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
               1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

    REQUIRE(ManYouRight(Markers4, word, NUMBERLETTERS, WORDSIZE) == 1);
}

TEST_CASE("non_repeating_characters")
{
    std::string word = "ANTILOPA";
    int WORDSIZE = 8;
    REQUIRE(non_repeating_characters(WORDSIZE, word) == 7);

    word = "BAOBAB";
    WORDSIZE = 6;
    REQUIRE(non_repeating_characters(WORDSIZE, word) == 3);

    word = "MANEJ";
    WORDSIZE = 5;
    REQUIRE(non_repeating_characters(WORDSIZE, word) == 5);

    word = "RATATYy";
    WORDSIZE = 7;
    REQUIRE(non_repeating_characters(WORDSIZE, word) == 5);

    word = "TROLLEyBYS";
    WORDSIZE = 10;
    REQUIRE(non_repeating_characters(WORDSIZE, word) == 9);
}
