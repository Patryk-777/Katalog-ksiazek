//
// Created by  tzakrzew on 09.11.22.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "InputHelper.h"

InputHelper helper;

TEST_CASE( "Sprawdzanie liczb:isNumber", "[input handling]" ) {
    SECTION ("checking positive integers")
    {
        REQUIRE(helper.isNumber("54"));
        CHECK(helper.isNumber("0") == true);
        CHECK(helper.isNumber("102012") == true);
        REQUIRE(helper.isNumber( "2137128372817397129379127391728387461786438712638162873"));
    }
}

TEST_CASE( "Sprawdzanie złych liczb:isNumber", "[input handling]")
{
    SECTION ("checking non numbers")
    {
        REQUIRE_FALSE(helper.isNumber("kupa"));
        REQUIRE_FALSE(helper.isNumber("jeden"));
        REQUIRE_FALSE(helper.isNumber(""));
        REQUIRE_FALSE(helper.isNumber( "112.121"));
        REQUIRE_FALSE(helper.isNumber( "112.121.2121212"));
    }

}

TEST_CASE("Sprawdzanie zakresu","[input handling]")
{
    REQUIRE(helper.isInRange(100,1,101));
    REQUIRE(helper.isInRange( 1,1,2));
    REQUIRE(helper.isInRange( 2,1,2));
    REQUIRE(helper.isInRange( 1,1,1));
    REQUIRE_FALSE(helper.isInRange( 3,1,2));
    REQUIRE_FALSE(helper.isInRange(9,100,200));
    REQUIRE_FALSE(helper.isInRange(-100,1,101));
}

TEST_CASE("Sprawdanie zatwierdzania liczb:positiveShortValidation", "[input handling]")
{
    SECTION ("checking numbers")
    {
        REQUIRE(helper.positiveShortValidation("0"));
        REQUIRE(helper.positiveShortValidation("23"));
        REQUIRE(helper.positiveShortValidation("1093"));
        REQUIRE_FALSE(helper.positiveShortValidation("123.33"));
        REQUIRE_FALSE(helper.positiveShortValidation("napis"));
        REQUIRE_FALSE(helper.positiveShortValidation("112napis"));
        REQUIRE_FALSE(helper.positiveShortValidation(""));
        REQUIRE_FALSE(helper.positiveShortValidation("123.33.9"));
    }SECTION ("Checking range")
    {
        REQUIRE(helper.positiveShortValidation("0"));
        REQUIRE(helper.positiveShortValidation("1322"));
        REQUIRE(helper.positiveShortValidation("32767"));
        REQUIRE_FALSE(helper.positiveShortValidation("-2"));
        REQUIRE_FALSE(helper.positiveShortValidation("32768"));
        REQUIRE_FALSE(helper.positiveShortValidation("12312638126"));
        REQUIRE_FALSE(helper.positiveShortValidation("-32721212121268"));

    }
}

    TEST_CASE("Sprawdzanie napisów pod względem zawierania liczb i innych znaków:hasNumber", "[input handling]")
    {
        SECTION("checking right strings")
        {
            REQUIRE(helper.hasNumber("Patryk Gawlowski"));
            REQUIRE(helper.hasNumber("C.S.S. Lewis"));
            REQUIRE(helper.hasNumber(""));
            REQUIRE(helper.hasNumber("Patryk Gawlowski i Tomasz Zakrzewski"));
            REQUIRE(helper.hasNumber("JOHNY DEPP"));
        }
        SECTION("checking wrong strings")
        {
            REQUIRE_FALSE(helper.hasNumber("P@tryk Gawlowski"));
            REQUIRE_FALSE(helper.hasNumber("3 Muszkieterow"));
            REQUIRE_FALSE(helper.hasNumber("STAR WARS 3"));
            REQUIRE_FALSE(helper.hasNumber("Patryk & Tomasz"));
        }
    }

