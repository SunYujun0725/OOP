#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define TRUE 1
#define FALSE 0
#define BOOL int
using namespace std;

class Cube
{
private:
    double x, y, z;

public:
    BOOL operator!=(const Cube &c);
    Cube(double x1, double y1, double z1);
    friend ostream &operator<<(ostream &output, const Cube &c);
    friend double &operator/(const Cube &c1, const Cube &c2);
};
#endif