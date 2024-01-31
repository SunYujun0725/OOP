#ifndef GRID_H
#define GRID_H

#define TRUE 1
#define FALSE 0
#define bool int

class Grid
{
public:
    // public static class constants,for direction indicators
    static const int NORTH = 0;
    static const int WEST = 1;
    static const int SOUTH = 2;
    static const int EAST = 3;

    // public member function
    Grid();
    Grid(int r, int c);
    Grid(int r, int c, int mr, int mc, int d);
    bool Move(int s);
    void TogglePath();
    void TurnLeft();
    void PutDown();
    bool PutDown(int r, int c);
    bool PickUp();
    bool PlaceBlock(int gr, int gc);
    void Grow(int gr, int gc);
    void Display() const;

    // Accessors
    bool FrontlsClear() const;
    bool RightlsClear() const;
    int GetRow() const;
    int GetCol() const;
    int GetNumRows() const;
    int GetNumCols() const;

    //
    int RandWall();
    int RandPoint(int rang);
    int RandMover_x();
};

#endif