#include "FileDirectory.h"
#include "CLI.h"
#include <string>



int main(int argc, char **argv)
{

    std::string path;
    if(argc!=1)
    {
        for (int i = 1; i < argc; i++)
        {
            path += argv[i];
        }
    }
    else
    {
        path="../lista_ksiazek.txt";
    }
    FileDirectory directory(path);
    CLI cli(directory);
    cli.showMenu();
    return 0;
}
