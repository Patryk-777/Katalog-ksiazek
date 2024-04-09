//
// Created by Patryk Gawłowski on 11/10/2022.
//


#include "CLI.h"

#include <limits>
#include <stdexcept>
#include <iostream>


void CLI::printMenu ()
{
    std::cout<<"1. Wyświetl książki"<<std::endl;
    std::cout<<"2. Dodaj książkę"<<std::endl;
    std::cout<<"3. Kasuj książkę"<<std::endl;
    std::cout<<"4. Wyszukaj książkę"<<std::endl;
    std::cout<<"-------------------"<<std::endl;
    std::cout<<"q. Wyjście"<<std::endl;
}

void CLI::showMenu()
{

    bool duration=true;
    while (duration)
    {
        OptionFromMenu option=(OptionFromMenu) NULL;
        std::string activity_s;
        printMenu();
        std::cin>>activity_s;
        if(activity_s.length()==1)
        {
            option=(OptionFromMenu) activity_s[0];
        }
        switch (option)
        {
            case SHOW_BOOKS:
            {
                browsingBooks();
                break;
            }
            case ADD_BOOKS:
            {
                addingBook();
                break;
            }
            case DELETE_BOOKS:
            {
                deletingBook();
                break;
            }
            case SEARCH_BOOK:
            {
                searchingBook();
                break;
            }
            case QUIT:
            {
                duration=false;
                break;
            }
            default:
            {
                std::cout<<"Nie istnieje taka możliwość wyboru"<<std::endl;
            }
        }
    }
}

void CLI::printHeader()
{
    std::cout<<"|-------------------------------------------------------------------------|"<<std::endl;
    std::cout<<"| Autor         | Tutuł                | Gatunek      | Liczba Stron| Id  |"<<std::endl;
    std::cout<<"|-------------------------------------------------------------------------|"<<std::endl;
}

void CLI::printFooter()
{
    std::cout<<"|-------------------------------------------------------------------------|"<<std::endl;
}

void CLI::printField (const std::string &value, short int length)
{

    std::cout << value.substr(0, length);
    for (short int i = length - value.length(); i > 0; i--)
    {
        std::cout << " ";
    }
    std::cout << "|";
}

void CLI::showBook(Book book)
{
    std::cout << "|";
    printField(book.author,15);
    printField(book.title,22);
    printField(book.genre,14);
    printField(std::to_string(book.noOfPages),13);
    printField(std::to_string(book.id), 5);
    std::cout << std::endl;
}

void CLI::browsingBooks()
{
    std::vector<Book> list_of_books=directory->getBooks();
    printHeader();
    for(const Book &book:list_of_books)
    {
        showBook(book);
    }
    printFooter();
}

void CLI::addingBook()
{
    std::string author;
    std::string title;
    std::string genre;
    std::string input;
    short int noOfPages;

    helper.clear_cin();
    author=helper.cinString("Podaj autora książki:");
    title= helper.cinString("Podaj tytuł książki:");
    genre= helper.cinString("Podaj gatunek książki:");
    noOfPages= helper.cinPositiveShort(input,"Podaj ilość stron książki: ");
    directory->addBook(Book(author, title, genre, noOfPages));
}

void CLI::searchingBook()
{
    char activity= helper.cinChar();
    helper.clear_cin();
    std::string searchingString=helper.cinString("Podaj szukaną frazę:");
    std::vector<Book> searchedBooks=directory->searchBook(searchingString, activity);
    if(searchedBooks.empty())
    {
        std::cout<<"Brak wyników wyszukiwania"<<std::endl;
    }
    else
    {
        printHeader();
        for(Book book:searchedBooks)
        {
            showBook(book);
        }
        printFooter();
    }
}

void CLI::deletingBook()
{
    if(directory->getBooks().size()==0)
    {
        std::cout<<"Nie masz żadnych książek w katalogu"<<std::endl;
        return void();
    }
    std::string input;
    short id = helper.cinPositiveShort(input, "Podaj Id książki, którą chcesz usunąć: ");
    if(directory->getBooks().size()>=id)
    {
        directory->deleteBook(id);
        std::cout << "Książka usunięta pomyślnie" << std::endl;
        return void();
    }
    if(directory->getBooks().size()<id)
    {
        std::cout<<"Nie ma książki o takim id"<<std::endl;
        return void();
    }


}

void CLI::startCLI(){
    showMenu();
}



CLI::CLI(Directory &directory) {
     this->directory=&directory;

}
