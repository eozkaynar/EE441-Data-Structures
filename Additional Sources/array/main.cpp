#include "panoi.hpp"
#include <iostream>


int main() {



    // String for print_backwards function
    char a[] = "EE441 Data Structures";

    // GCD and LCM
    int gcd1,lcm1;
    // Initialize the game with 4 discs
    int num_discs = 4;

    Hanoi game(num_discs);

    // Show the game board before solving
    game.ShowBoard();
    // Solve hanoi
    solve_hanoi(game);
    // Solve the game board after solving
    game.ShowBoard();



    return 0;
}
