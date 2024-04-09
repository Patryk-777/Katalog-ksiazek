
#include "Directory.h"



#pragma




class FileDirectory: public Directory {

    std::string filePath;
public:
    bool addBook(const Book &book) override;
    void deleteBook(short int index) override;
    void writeToFile();
    void readFromFile();
    FileDirectory(std::string FileLocation)
    {
        filePath=FileLocation;
        readFromFile();
    }

};


