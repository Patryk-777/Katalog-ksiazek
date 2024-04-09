//
// Created by Patryk Gawłowski on 20/09/2022.
//

#include "Directory.h"

#include <stdexcept>
#include <cctype>



std::vector<Book> Directory::getBooks()
{
    return list_of_books;
}
//otestować do końca
bool Directory::addBook(const Book &book)
{
    if(hasEmptyField(book))
        return false;
    if(isBookEqualToExisting(book))
        return false;

    short id=getBooks().size()+1;
    Book ksiazka{book.author, book.title, book.genre, book.noOfPages, id};
    list_of_books.push_back(ksiazka);
    return true;
}

std::string Directory::getOption(char option,const Book &book)
{
    std::string field;
    std::string comparison;
    switch (option)
    {
        case '1':
        {
            field=book.author;
            break;
        }
        case '2':
        {
            field=book.title;
            break;
        }
        case '3':
        {
            field=book.genre;
            break;
        }
    }
    for(char i:field)
    {
        comparison+=tolower(i);
    }
    return comparison;
}

std::vector<Book> Directory::searchBook(const std::string &input, char option)
{
    std::vector<Book> foundBooks;
    for(char i:input)
    {
        tolower(i);
    }
    std::string comparison;
    for(Book book:list_of_books)
    {
        comparison= getOption(option, book);
        if(comparison.find(input)!=std::string::npos)
        {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;

}




void Directory::deleteBook(short int index)
{

                list_of_books.erase(list_of_books.begin() + index - 1);
                for (short i = index - 1; i < list_of_books.size(); i++) {
                    list_of_books[i].id=list_of_books[i].id-1;
                }

            return void();
}

bool Directory::hasEmptyField(const Book &book) {
    if(book.author.empty() or book.title.empty() or book.genre.empty() or book.noOfPages==0)
        return true;
    return false;
}

bool Directory::isBookEqualToExisting(const Book &book) {

    for(Book exsisting:list_of_books)
    {
        if(isBookTheSame(exsisting, book))
            return true;
    }
    return false;
}

bool Directory::isBookTheSame(const Book &book_1,const Book &book_2) {
    if(book_1.author==book_2.author and book_1.title==book_2.title and book_1.genre==book_2.genre and book_1.noOfPages==book_2.noOfPages)
        return true;
    return false;
}




