#include "InputHelper.h"

#include <climits>
#include <limits>
#include <iostream>
#include <exception>

void InputHelper::clear_cin()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool InputHelper::isRightChar(std::string input) {
    if (input.length() != 1)
    {
        std::cout<<"Nie ma takiej opcji wyboru"<<std::endl;
        return false;
    }
    else if(input[0]!='1' && input[0]!='2' && input[0]!='3')
    {
        std::cout<<"Nie ma takiej opcji wyboru"<<std::endl;
        return false;
    }
    return true;
}

char InputHelper::cinChar()
{
    std::string input;
    do
    {
        printSearchingMenu();
        std::cin >> input;
    }
    while(!isRightChar(input));
    return input[0];
}

bool InputHelper::isNumber(const std::string &input)
{
    if (input.length() == 0) return false;
    for(char i:input)
    {
        if(!isdigit(i))
        {
            return false;
        }
    }
    return true;
}

bool InputHelper::isInRange(int liczba, int min, int max)
{
    if(liczba>max || liczba<min)
    {
        return false;
    }
    return true;
}

//do testów+
bool InputHelper::positiveShortValidation(const std::string &input)
{
    int liczba;
    if(!isNumber(input))
        return false;
    try
    {
        liczba = stoi(input);
    }
    catch(std::exception)
    {
        return false;
    }
    if(isInRange(liczba, 0, SHRT_MAX))
        return true;

    std::cout<<"Musisz podać liczbę z zakresu: "<<0<<"-"<<SHRT_MAX<<std::endl;
    return false;

}

//do testów+
bool InputHelper::hasNumber(const std::string &input)
{
    for(char i:input)
    {
        if (!isalpha(i) && !isspace(i) && !(i == '.'))
        {
            return false;
        }
    }
    return true;
}

//do testów
bool InputHelper::stringValidation(const std::string &input)
{
    if(hasNumber(input))
        return true;

    std::cout<<"Podałeś niepoprawny napis"<<std::endl;
    return false;
}

std::string InputHelper::cinString(const std::string &output)
{
    std::string input;
    do
    {
        std::cout << output << std::endl;
        std::getline(std::cin, input);
    }
    while(!stringValidation(input));
    return input;
}

short InputHelper::cinPositiveShort(std::string input, const std::string &output)
{
    do
    {
        std::cout<<output<<std::endl;
        std::cin >> input;
    }
    while(!positiveShortValidation(input));
    return static_cast<short>(std::stoi(input));
}

void InputHelper::printSearchingMenu () {
    std::cout << "Wybierz po czym chcesz wyszukać książkę: " << std::endl;
    std::cout << "1. Po autorze" << std::endl;
    std::cout << "2. Po tytule" << std::endl;
    std::cout << "3. Po gatunku" << std::endl;
}

