
#include <string>

#pragma once

struct Book
{
    std::string author;
    std::string title;
    std::string genre;
    short int noOfPages;
    short int id;
    Book(std::string author, std::string title, std::string genre, short int noOfPages,short int id=0):author(author), title(title), genre(genre), noOfPages(noOfPages), id(id)
    {}



};

