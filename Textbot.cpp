/*
driver code to run the project
there are two input options are available 1) reading from file 2) pasting on console
    
*/

#include "Summarizer.h"

int main()
{
    summarizer s;
    std::string filename, data, line;
    int choice;
    
    std::cout << "Enter 1 For Filename and 2 For Input Paragraph. " << std::endl;
    std::cin >> choice;
    if (choice == 1)
    {
        std::cout << "Enter file name with txt" << std::endl;
        std::cin >> filename;
        std::ifstream file(filename);
        system("cls");
        s.summaryMaker(file);
    }
    else if(choice == 2)
    {
        std::fflush(stdout);
        std::cout << "Enter paragraph." << std::endl;
        do
        {
            std::cin >> line;
            std::getline(std::cin, line);
            data += line;
        } while (line != "");
        system("cls");
        s.summaryMaker(data);
    }
    else
    {
        std::cout << "Sorry! Invalid choice" << std::endl;
       
    }
 
    return 0;
}