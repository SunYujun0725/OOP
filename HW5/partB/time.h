#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define TRUE 1
#define FALSE 0
#define BOOL int
using namespace std;

class Time
{
private:
    int day, hours, minutes, seconds;
    string in;

public:
    Time();
    Time(int s);
    Time(int d, int h, int m, int s);
    int convert_s(int d, int h, int m, int s);                  //將全部轉成seconds
    void simplified_time(int s);                                //將秒換成對的時間
    friend ostream &operator<<(ostream &output, const Time &t); //輸出
    friend istream &operator>>(istream &in, Time &t);           //輸入並轉成正確的時間表示
    Time operator+(const Time &t);                              //兩個class Time相加
    Time operator-(const Time &t);                              //兩個class Time相減
    //比較兩個class Time
    BOOL operator<(const Time &t);
    BOOL operator>(const Time &t);
    BOOL operator<=(const Time &t);
    BOOL operator>=(const Time &t);
    BOOL operator==(const Time &t);
    BOOL operator!=(const Time &t);
    Time operator+(int right);                      //一個class Time加一整數
    Time operator-(int right);                      //一個class Time減一整數
    Time operator++();                              // prefix++
    const Time operator++(int x);                   // postfix++
    Time operator--();                              // prefix--
    const Time operator--(int x);                   // postfix--
    friend Time operator+(int left, const Time &t); //一整數加一個class Time
    friend Time operator-(int left, const Time &t); //一整數減一個class Time
};

#endif