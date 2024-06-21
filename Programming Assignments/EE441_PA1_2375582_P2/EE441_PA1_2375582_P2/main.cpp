#include "Hanoi.hpp"
#include <iostream>
#include "AlgorithmicComplexity.hpp"
#include "benchmark.hpp"


int main() {



    // String for print_backwards function
    char a[] = "EE441 Data Structures";

    // GCD and LCM
    int gcd1,lcm1;
    // Initialize the game with 4 discs
    int num_discs = 3;

    Hanoi game(num_discs);

    // Show the game board before solving
    game.ShowBoard();
    // Solve hanoi
    solve_hanoi(game);
    // Solve the game board after solving
    game.ShowBoard();

    // call print_backwards
    print_backwards(a);

    // greatest common divisor of two integers
    gcd1 = gcd(12,18);
    cout <<" " << endl;
    cout <<"gcd: " <<gcd1 << endl;
    cout <<" " << endl;
    // least common multiple of two integers
    lcm1 = lcm(12,18);
    cout <<"lcm: " << lcm1;
/*
    // BENCHMARK
    benchmark(wrapper_solve_hanoi);
    benchmark(wrapper_print_backwards);
    benchmark(wrapper_gcd);
	benchmark(wrapper_lcm);
*/
    return 0;
}
