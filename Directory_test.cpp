//
// Created by tzakrzew on 18.11.22.
//

#include "catch.hpp"
#include "Directory.h"

TEST_CASE("Testowanie dodawania ksiazek","[Directory]")
{
    SECTION("Dodwanie pozytywne przypadki")
    {
        Directory directory;
        REQUIRE(directory.getBooks().size() == 0);
        directory.addBook(Book("tomek", "domek", "fantay", 20));
        REQUIRE(directory.getBooks().size() == 1);
        directory.addBook(Book("tomek", "domek", "fantay", 20));
        REQUIRE(directory.getBooks().size() == 1);
        directory.addBook(Book("patryk", "domek", "fantay", 20));
        REQUIRE(directory.getBooks().size() == 2);
    }
    SECTION("Negatywne")
    {
        Directory directory;
        REQUIRE(directory.getBooks().size() == 0);
        directory.addBook(Book("","","",0));
        REQUIRE(directory.getBooks().size() == 0);
        directory.addBook(Book("Patryk","","",0));
        REQUIRE(directory.getBooks().size() == 0);
        directory.addBook(Book("Patryk","Katalog","Cpp",0));
        REQUIRE(directory.getBooks().size() == 0);
        directory.addBook(Book("Patryk","Katalog","",10));
        REQUIRE(directory.getBooks().size() == 0);
        REQUIRE(directory.getBooks().size() == 0);
        directory.addBook(Book("Patryk","","Cpp",10));
        REQUIRE(directory.getBooks().size() == 0);
        directory.addBook(Book("","Katalog","Cpp",10));
        REQUIRE(directory.getBooks().size() == 0);
    }
}