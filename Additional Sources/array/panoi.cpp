#include "panoi.hpp"

bool Hanoi::LegalMove(Discs &disc_from,Discs &disc_to)
{
    int diameter_from,diameter_to; //diameters
    // Get diameters
    diameter_from  = disc_from.returnDiameter();
    diameter_to    = disc_to.returnDiameter();
    // check destination diameter is larger than source diameter or destination rod is empty
    return ((diameter_from < diameter_to) || (diameter_to == 0));
}
// Check that index is between 0 and 2
bool Hanoi::checkIndex(int index)
{
    return((0<= index) && (index <3));
}

void Hanoi::move(int from,int to)
{
    bool validFrom = false, validTo = false;  // initialize valid parameters
    // check rod indices are valid
    validFrom      = checkIndex(from);
    validTo        = checkIndex(to);

    if(validFrom && validTo)
    {
        Discs temp, topDisc;  //source disc and destination disc
        int top_from,i2;      // Top item of source rod

        // Get the top index of source rod
        top_from = rods.returnTop(from);
        temp = rods.Peek(from);
        // Get the top item of destination rod
        topDisc = rods.Peek(to);
        if (LegalMove(temp,topDisc))
        {
            // Destination disc
            temp = rods.Pop(from);
            // Push 0 to source rod to indicate empty stack position
            rods.PushZero(from,top_from++);
            // Push the source disc to destination rod
            rods.Push(temp,to);
            // Display
            cout << "Disc "<< temp.returnDiameter() << " is moved from Rod "<< from <<" to "<< to << endl;
        }
        else
        {
            cout<< "Illegal Move"<< endl;
            exit(1);
        }
    }
    else
        cerr << "Rod numbers are not valid."<< endl;
}

void Hanoi::ShowBoard(void)
{
    for(int i = 19; i >= 0; i--)
    {
        Discs d0,d1,d2;
        // Get discs from desired rod and indices
        d0 = rods.ShowElement(0,i);
        d1 = rods.ShowElement(1,i);
        d2 = rods.ShowElement(2,i);
        // Display their diameters
        cout << d0.returnDiameter() << d1.returnDiameter() << d2.returnDiameter()<< endl;
    }
    cout << "|||" << endl;


}
int* Hanoi::returnRodTops(int arr[]) const
{
    // Get top indices of rods
    arr[0]  = rods.returnTop(0);
    arr[1]  = rods.returnTop(1);
    arr[2]  = rods.returnTop(2);
    return arr;
}

void solve_hanoi_recursive(Hanoi&Game, int DiscNum,int source,int middle,int destination)
{
    // Termination
    if (DiscNum == 1)
        // Move the first disc(biggest) from source the destination rod
        Game.move(source,destination);
    else
    {
        // Solve hanoi for the top (n-1) discs from source to middle rod
        solve_hanoi_recursive(Game,DiscNum-1,source,destination,middle);
        // Move the nth disc from source to destination
        Game.move(source,destination);
        // Solve hanoi for the top (n-1) discs from middle to destination rod
        solve_hanoi_recursive(Game,DiscNum-1,middle,source,destination);
    }

}

void solve_hanoi(Hanoi& Game)
{
    // Give names to rods
    int source = 0,middle = 1,destination = 2;
    // Number of discs in rods
    int *numOfDiscs, DiscNum;
    int arr[3];                 // Array to hold number of the discs in the three rod

    // Get the number of discs at each rod
    numOfDiscs = Game.returnRodTops(arr);
    DiscNum = *(numOfDiscs)+1;
    // Solve hanoi recursively
    solve_hanoi_recursive(Game,DiscNum,source,middle,destination);

}

