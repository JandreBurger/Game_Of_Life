#include "grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    Grid grid;
int percentage ;

std:: cout<< "Enter starting life channce in a percentage : ";
std::cin >> percentage ;
std::cin.ignore();

grid.alivepercentage(percentage);

  char input ;

    while (true)
    {
        grid.display(); // call display 
        
        std::cout << "\nPress Enter to advance press n to stop : ";
        std::cin.get(input);

        if(input =='n'){ // breaks to stop indefinite looping 
            break;
        }

        grid.update();

        std::cout << "\n";
    }

    return 0;
}