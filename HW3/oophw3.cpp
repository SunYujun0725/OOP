#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Coins
{
public: //公有（可外部訪問、存取、有繼承）
    int intvalue;
    Coins(const double doublecoin, const char *coinvalue, const int point); //這是構造函數(constructor)
    inline const double print_dollars()
    { //回傳dollar_value
        return dollars;
    }
    inline const double print_cents()
    { //回傳dollar_value
        return cents;
    }
    inline const int print_q()
    { //回傳q
        return q;
    }
    inline const int print_d()
    { //回傳d
        return d;
    }
    inline const int print_n()
    { //回傳n
        return n;
    }
    inline const int print_p()
    { //回傳p
        return p;
    }

private:                 //私有（不可外部訪問、存取、沒有繼承）
    double dollar_value; //要回傳的dollar value
    int q, d, n, p;
    int dollars, cents;
    int point;                                                                              //存小數點位置
    inline void savevalue(const double doublecoin, const char *coinvalue, const int point); //儲存輸入進來的值並存成int型態
    inline void computed(const int intvalue);                                               //計算qdnp值
    inline int print();                                                                     //印出答案
};
//建構函式定義
Coins::Coins(const double doublecoin, const char *coinvalue, const int point)
{

    if (coinvalue[point + 3] != '\0')
    { //如果小數點後第三格不為結束符代表輸入錯誤
        cout << "輸入錯誤" << endl;
    }
    else
    {
        dollar_value = doublecoin;               //用class裡面的變數去存在main函式已經轉換完的double型態
        savevalue(doublecoin, coinvalue, point); //儲存輸入進來的值並存成int型態
        intvalue = dollars * 100 + cents;        //原本輸入的值乘100（int型態）
        computed(intvalue);                      //計算qdnp值
        print();
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

inline int Coins::print()
{ //印出答案

    cout << "$" << print_dollars() << "." << print_cents()
         << " = " << print_q() << " quarters"
         << ", " << print_d() << " dimes"
         << ", " << print_n() << " nickels"
         << ", " << print_p() << " pennies" << endl;
    return 0;
}

int main(int argc, char **argv)
{
    int count = argc;
    for (int i = 1; i <= count; i++)
    {
        char *coinvalue = argv[i];
        double doublecoin = stod(coinvalue); //將輸入字串轉double
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
