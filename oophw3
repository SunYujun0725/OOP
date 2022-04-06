#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Coins
{
public: //公有（可外部訪問、存取、有繼承）
    int intvalue;
    int point;                                            //存小數點位置
    Coins(double doublecoin, char *coinvalue, int point); //這是構造函數(constructor)

private: //私有（不可外部訪問、存取、沒有繼承）
    int q, d, n, p;
    int dollars, cents;
    inline void savevalue(const double doublecoin, const char *coinvalue, const int point); //儲存輸入進來的值並存成int型態
    inline void computed(const int intvalue);                                               //計算qdnp值
    int print(const int q, const int d, const int n, const int p);                          //印出答案
};
//建構函式定義
Coins::Coins(double doublecoin, char *coinvalue, int point)
{

    if (coinvalue[point + 3] != '\0')
    { //如果小數點後第三格不為結束符代表輸入錯誤
        cout << "輸入錯誤" << endl;
    }
    else
    {
        savevalue(doublecoin, coinvalue, point); //儲存輸入進來的值並存成int型態
        intvalue = dollars * 100 + cents;        //原本輸入的值乘100（int型態）
        computed(intvalue);                      //計算qdnp值
        print(q, d, n, p);
    }
}

// member function定義
inline void Coins::savevalue(const double doublecoin, const char *coinvalue, const int point)
{ //儲存輸入進來的值並將dollars,cents存成int型態

    dollars = (int)doublecoin;
    cents = (((int)coinvalue[point + 1] - 48) * 10) + ((int)coinvalue[point + 2] - 48);
}

inline void Coins::computed(const int intvalue)
{ //計算qdnp值

    q = intvalue / 25;
    d = (intvalue % 25) / 10;
    n = ((intvalue % 25) % 10) / 5;
    p = ((intvalue % 25) % 10) % 5;
}

int Coins::print(const int q, const int d, const int n, const int p)
{ //印出答案

    cout << "$" << dollars << "." << cents << " = " << q << " quarters"
         << ", " << d << " dimes"
         << ", " << n << " nickels"
         << ", " << p << " pennies" << endl;
    return 0;
}

int main(int argc, char **argv)
{

    int count = argc;
    for (int i = 1; i <= count; i++)
    {
        char *coinvalue = argv[i];
        double doublecoin = atoi(coinvalue); //將輸入字串轉double
        int j = 0;
        while (coinvalue[j] != '\0')
        {
            if (coinvalue[j] == '.')
            {
                break;
            }
            j++;
        }
        Coins coins(doublecoin, coinvalue, j);
    }
    return 0;
}
