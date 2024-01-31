#include <iostream>
using namespace std;
#include "Grid.h"

int main()
{
    // set up the initial grid
    Grid g(9, 15, 2, 13, Grid::WEST);
    g.PutDown(2, 1);
    for (int i = 0; i < 7; i++)
    {
        g.PlaceBlock(i, 11);
        g.PlaceBlock(i, 7);
        g.PlaceBlock(i, 3);
        g.PlaceBlock(i + 2, 5);
        g.PlaceBlock(i + 2, 9);
    }

    g.Display(); // A

    // now start moving
    g.TurnLeft();
    g.Move(5);

    g.Display(); // B

    g.TurnLeft();
    g.TurnLeft();
    g.TurnLeft();
    g.Move(1);

    g.Display(); // C

    for (int i = 0; i < 2; i++)
    {

        g.Move(2);

        g.Display(); // D I

        g.TurnLeft();
        g.TurnLeft();
        g.TurnLeft();
        g.Move(6);

        g.Display(); // E J

        g.PutDown();

        g.Display(); // F K

        g.TurnLeft();
        g.Move(2);

        g.Display(); // G L

        g.TurnLeft();
        g.Move(6);

        g.Display(); // H M

        g.TurnLeft();
        g.TurnLeft();
        g.TurnLeft();
    }

    g.Move(3);

    g.Display(); // N

    g.TurnLeft();
    g.TurnLeft();
    g.TurnLeft();
    g.Move(5);

    g.Display(); // O

    g.PickUp();

    g.Display(); // P

    g.TurnLeft();
    g.Move(1);

    g.Display(); // Q

    g.TogglePath();

    g.Display(); // R

    g.TogglePath();

    g.Display(); // S

    g.Grow(3, 5);

    g.Display();

    /*Grid g;
    g.Grow(1,2);
    g.Display();*/

    /*Grid g(2, 5);
    g.Display();
    g.FrontlsClear();
    g.RightlsClear();
    g.Grow(3, 4);
    g.Display();
    g.TurnLeft();
    g.TurnLeft();
    g.Display();*/

    return 0;
}
