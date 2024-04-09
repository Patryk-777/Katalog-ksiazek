#include "Book.h"

#include <vector>


#pragma once



class Directory
{
    std::vector<Book> list_of_books;
    bool hasEmptyField(const Book &book);
    bool isBookTheSame(const Book &book_1, const Book &book_2);
    bool isBookEqualToExisting(const Book &book);
    std::string getOption(char option,const Book &book);
public:

    std::vector<Book> getBooks();
    virtual bool addBook(const Book &book);
    std::vector<Book> searchBook(const std::string &input, char option);
    virtual void deleteBook(short int index);


};



