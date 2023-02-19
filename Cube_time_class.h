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
    int convert_s(int d, int h, int m, int s); //將全部轉成seconds
    void simplified_time(int s);               //將秒換成對的時間
    friend ostream &operator<<(ostream &output, const Time &t);
    friend istream &operator>>(istream &in, Time &t);
    Time operator+(const Time &t);
    Time operator-(const Time &t);
    BOOL operator<(const Time &t);
    BOOL operator>(const Time &t);
    BOOL operator<=(const Time &t);
    BOOL operator>=(const Time &t);
    BOOL operator==(const Time &t);
    BOOL operator!=(const Time &t);
    Time operator+(int right);
    Time operator-(int right);
    Time operator++();
    Time operator++(int x);
    Time operator--();
    Time operator--(int x);
};

#endif
