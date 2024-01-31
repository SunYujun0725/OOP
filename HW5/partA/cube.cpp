#include <iostream>
#include <cstring>
#include <cstdlib>
#include "cube.h"
double ans;
Cube::Cube(double x1, double y1, double z1)
{
    x = x1;
    y = y1;
    z = z1;
}

BOOL Cube::operator!=(const Cube &c)
{
    double compare1, compare2;
    compare1 = (this->x) * (this->y) * (this->z);
    compare2 = (c.x) * (c.y) * (c.z);
    if (compare1 != compare2)
    {
        return TRUE;
    }
    return FALSE;
}

ostream &operator<<(ostream &output, const Cube &c)
{
    output << c.x << " " << c.y << " " << c.z;
    return output;
}

double &operator/(const Cube &c1, const Cube &c2)
{
    // double ans;
    ans = (c1.x + c1.y + c1.z) / (c2.x + c2.y + c2.z);
    return ans;
}