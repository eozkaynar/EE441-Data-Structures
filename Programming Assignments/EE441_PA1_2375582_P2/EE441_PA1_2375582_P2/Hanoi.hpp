#ifndef HANOI_HPP_INCLUDED
#define HANOI_HPP_INCLUDED
#include "Rods.hpp"
class Discs
{
        int diameter; // Diameter of disc
    public:
        // constructors
        Discs(int d):diameter(d)
        {}
        Discs(void)
        {}
        // Get the diameter of disc
        int returnDiameter(void) const
        {
            return diameter;
        }
};

class Hanoi
{
    private:
        Rod2D<Discs> rods;                    // Model of three rod
        int numberOfDiscs;                              // number of discs to use
    public:
        // constructor to initialize the game
        Hanoi(int n):numberOfDiscs(n)
        {
            // Start the game by initializing the discs in the first rod
            for (int i = numberOfDiscs; i > 0; i--)
            {
                rods.Push(Discs(i),0);
            }

        }
        // move function to change place of the disc from one rod to another
        void move(int from, int to);
        // Check whether the move is legal or illegal
        bool LegalMove(Discs &disc1,Discs &disc2);
        // Check are rod indices valid
        bool checkIndex(int index);
        // Function that shows board
        void ShowBoard(void);
        // Return the discs numbers in each rod
        int* returnRodTops(int arr[]) const;
};
// Solve hanoi recursive
void solve_hanoi_recursive(Hanoi&Game, int DiscNum,int source,int middle,int destination);
// Solve hanoi
void solve_hanoi(Hanoi& Game);

#endif // HANOI_HPP_INCLUDED
