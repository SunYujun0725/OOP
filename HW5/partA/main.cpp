#include <iostream>
#include "cube.h"
using namespace std;
int main()
{
    Cube c1(10, 20, 30);
    Cube c2(20, 10, 30);
    if (c1 != c2)
        cout << c1 << " != " << c2 << " is TRUE\n\n";

    Cube c3(10, 10, 30);
    Cube c4(20, 10, 30);
    if (c3 != c4)
        cout << c3 << " != " << c4 << " is TRUE\n\n";

    cout << c1 << " / " << c2 << " = " << c1 / c2 << '\n';
    cout << c3 << " / " << c4 << " = " << c3 / c4 << '\n';
}