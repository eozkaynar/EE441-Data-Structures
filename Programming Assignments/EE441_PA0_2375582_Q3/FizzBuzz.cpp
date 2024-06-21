#include <iostream>
#include "FizzBuzz.hpp"

void FizzBuzz(int endNumber)
{
    for (int i = 1; i < endNumber+1; i++)
    {
        if ((i%3 == 0)&&(i%5 == 0))
        {
            std::cout << " FizzBuzz ";
        }

        else if (i%5 == 0)
            {
                std::cout << " Buzz ";
            }
        else if (i%3 == 0)
        {
            std::cout << (" Fizz ");
        }

        else
        {
            std::cout << i << " ";
        }

    }
}

int getInput()
{
    int input;
    std::cout << "Number:";
    std::cin >> input;
    if (input >= 0)
        return input;
    else
        std::cout << "Try again: ";
        std::cin >> input;

}
