
#include <string>


#pragma




class InputHelper {

public:

    std::string cinString( const std::string &output);
    void clear_cin();
    bool isRightChar(std::string input);
    char cinChar();
    bool isNumber(const std::string &input);
    bool isInRange(int liczba, int min, int max);
    bool positiveShortValidation(const std::string &input);
    bool hasNumber(const std::string &input);
    bool stringValidation(const std::string &input);
    short cinPositiveShort(std::string input, const std::string &output);
    void printSearchingMenu ();
};



