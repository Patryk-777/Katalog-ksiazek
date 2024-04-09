#include "Directory.h"
#include "InputHelper.h"




#pragma KATALOG_KSIAZEK_CLI_H




class CLI {

    Directory *directory;
    InputHelper helper;
    enum OptionFromMenu
    {
        SHOW_BOOKS=49,
        ADD_BOOKS=50,
        DELETE_BOOKS=51,
        SEARCH_BOOK=52,
        QUIT=113
    };


public:

    void startCLI();
    void printField (const std::string &value, short int length);
    void showMenu();
    void browsingBooks();
    void addingBook();
    void searchingBook();
    void deletingBook();
    void showBook(Book book);
    void printFooter();
    void printHeader();
    void printMenu ();
    explicit CLI(Directory &directory);


};



