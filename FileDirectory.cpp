
#include "FileDirectory.h"

#include <fstream>

void FileDirectory::writeToFile() {

    std::ofstream writeStream;
    writeStream.open(filePath);
    for(Book &book:getBooks())
    {
        writeStream<<book.author<<";"<<book.title<<";"<<book.genre<<";"<<book.noOfPages<<";"<<std::endl;
    }
    writeStream.close();
}

void FileDirectory::readFromFile() {
    std::ifstream readStream;
    readStream.open(filePath);

    for( std::string line; getline( readStream, line ); )
    {
        size_t pos;
        std::string token;
        std::vector<std::string> bookInformations;
        while ((pos = line.find(';')) != std::string::npos)
        {
            bookInformations.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        addBook(Book{bookInformations[0], bookInformations[1], bookInformations[2], static_cast<short>(stoi(bookInformations[3]))});
    }
    readStream.close();

}

bool FileDirectory::addBook(const Book &book) {
    Directory::addBook(book);
    writeToFile();
    return true;
}

void FileDirectory::deleteBook(short index) {
    Directory::deleteBook(index);
    writeToFile();

}
