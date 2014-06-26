#include <iostream>
#include "Engine.h"
#include "RandomEngine.h"

int main()
{
	Engine e;
    char choice;
    while (true)
    {
        std::cout << "Would you like to play another game? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            std::cout << "Remember to empth the output_data folder before the next game!" << std::endl;
            std::cout << std::endl;
            Engine e;
        }
        else
            break;
    }
	return 0;
}