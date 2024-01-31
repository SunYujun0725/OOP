#include <iostream>
#include "time.h"
using namespace std;
int main()
{
    Time t1, t2, t3(123456), t4(987654321);
    cout << "t1 = " << t1 << '\n';
    cout << "t2 = " << t2 << '\n';
    cout << "t3 = " << t3 << '\n';
    cout << "t4 = " << t4 << '\n';
    cout << "Enter first Time object (DAYS~HH:MM:SS): ";
    cin >> t1;
    cout << "Enter second Time object (DAYS~HH:MM:SS): ";
    cin >> t2;
    cout << "\n\n";
    cout << t1 << " + " << t2 << " = " << t1 + t2 << '\n';
    cout << t1 << " - " << t2 << " = " << t1 - t2 << "\n\n";
    if (t1 < t2)
        cout << t1 << " < " << t2 << " is TRUE\n";
    if (t1 > t2)
        cout << t1 << " > " << t2 << " is TRUE\n";
    if (t1 <= t2)
        cout << t1 << " <= " << t2 << " is TRUE\n";
    if (t1 >= t2)
        cout << t1 << " >= " << t2 << " is TRUE\n";
    if (t1 == t2)
        cout << t1 << " == " << t2 << " is TRUE\n";
    if (t1 != t2)
        cout << t1 << " != " << t2 << " is TRUE\n\n";
    cout << t1 << " + 654321 = " << t1 + 654321 << '\n';
    cout << t2 << " + 15263748 = " << t2 + 15263748 << '\n';
    cout << t1++ << '\n';
    cout << t1 << '\n';
    cout << ++t1 << '\n';
    cout << t1 << '\n';
    cout << t2-- << '\n';
    cout << t2 << '\n';
    cout << --t2 << '\n';
    cout << t2 << '\n';
    Time t5(-1234), t6(10, 23, 34, -4), t7(-2, 3, 32, 4), t8(23, -3, 2, 4), t9(23, 34, -9, 2);
    cout << "t5 = " << t5 << '\n';
    cout << "t6 = " << t6 << '\n';
    cout << "t7 = " << t7 << '\n';
    cout << "t8 = " << t8 << '\n';
    cout << "t9 = " << t9 << '\n';
    Time t10, t11, t12;
    cout << "Enter second Time object (DAYS~HH:MM:SS): ";
    cin >> t10;
    cout << "Enter second Time object (DAYS~HH:MM:SS): ";
    cin >> t11;
    cout << "Enter second Time object (DAYS~HH:MM:SS): ";
    cin >> t12;
    cout << "t10 = " << t10 << '\n';
    cout << "t11 = " << t11 << '\n';
    cout << "t12 = " << t12 << '\n';
    cout << t2 << " - " << t1 << " = " << t2 - t1 << "\n\n";
    cout << t2 << " - 15263748 = " << t2 - 15263748 << '\n';
    if (t7 == t5)
        cout << t7 << " == " << t5 << " is TRUE\n";
    if (t7 != t5)
        cout << t7 << " != " << t5 << " is TRUE\n";
    if (t7 >= t5)
        cout << t7 << " >= " << t5 << " is TRUE\n";
    if (t7 <= t5)
        cout << t7 << " <= " << t5 << " is TRUE\n";
    if (t7 > t5)
        cout << t7 << " > " << t5 << " is TRUE\n";
    if (t7 < t5)
        cout << t7 << " < " << t5 << " is TRUE\n\n";

    cout << t5 << " + " << t8 << " = " << t5 + t8 << '\n';
    cout << t5 << " - " << t8 << " = " << t5 - t8 << '\n';
    cout << t5++ << '\n';
    cout << t5 << '\n';
    cout << ++t5 << '\n';
    cout << t5 << '\n';
    cout << t7-- << '\n';
    cout << t7 << '\n';
    cout << --t7 << '\n';
    cout << t7 << '\n';
    cout << t2 << '\n';
    cout << "654321 + " << t2 << " = " << 654321 + t2 << '\n';
    Time t15(999999999);
    cout << t15 << '\n';
    cout << "999999999 - " << t2 << " = " << 999999999 - t2 << '\n';
}
