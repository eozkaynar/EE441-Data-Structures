#ifndef PANOI_H_INCLUDED
#define PANOI_H_INCLUDED
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
        Stack<Discs> rod0,rod1,rod2;                    // Model of three rod
        int numberOfDiscs;                              // number of discs to use
    public:
        // constructor to initialize the game
        Hanoi(int n):numberOfDiscs(n)
        {
            // Push zero diameter disc to indicate the empty rods
            rod0.Push(Discs(0));
            rod1.Push(Discs(0));
            rod2.Push(Discs(0));
            // Start the game by initializing the discs in the first rod
            for (int i = numberOfDiscs; i > 0; i--)
            {
                rod0.Push(Discs(i));
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
        // Hold the rods without zeros implement move easily
        Stack<Discs> deleteZeros(Stack<Discs> &rod);
};
// Solve hanoi recursive
void solve_hanoi_recursive(Hanoi&Game, int DiscNum,int source,int middle,int destination);
// Solve hanoi
void solve_hanoi(Hanoi& Game);
#endif // HANOI_HPP_INCLUDED



#endif // PANOI_H_INCLUDED
