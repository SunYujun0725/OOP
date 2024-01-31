#include <iostream>
#include <cstring>
#include <cstdlib>
#include "time.h"

Time::Time() //無參數的construstor
{
    day = hours = minutes = seconds = 0; //初始化為00~00:00:00
}

Time::Time(int s) //帶一個seconds參數的construstor
{
    if (s < 0) //若seconds<0則初始化為00~00:00:00
    {
        day = hours = minutes = seconds = 0;
    }
    else
    {
        seconds = s;
        day = hours = minutes = 0;
        simplified_time(s); //轉換成正確時間表示
    }
}

Time::Time(int d, int h, int m, int s) //帶四個參數的construstor
{
    if (d < 0 || h < 0 || m < 0 || s < 0)
    { //若有其中一項<0則初始化為00~00:00:00
        day = hours = minutes = seconds = 0;
    }
    else
    {
        seconds = s;
        minutes = m;
        hours = h;
        day = d;
        int se = convert_s(d, h, m, s); //將全部轉成seconds
        simplified_time(se);            //轉換成正確時間表示
    }
}

int Time::convert_s(int d, int h, int m, int s) //將全部轉成seconds
{
    int se = 0;
    se = s;
    se += d * 24 * 60 * 60;
    se += h * 60 * 60;
    se += m * 60;
    return se;
}

void Time::simplified_time(int s) //轉成正確的時間表示
{
    seconds = s % 60;
    minutes = ((s / 60) % 60);
    hours = (((s / 60) / 60) % 24);
    day = (((s / 60) / 60) / 24);
}

ostream &operator<<(ostream &output, const Time &t) //輸出，且要符合格式day~hh:mm:ss
{
    int h1, h2, m1, m2, s1, s2;
    s1 = t.seconds / 10;
    s2 = t.seconds % 10;
    m1 = t.minutes / 10;
    m2 = t.minutes % 10;
    h1 = t.hours / 10;
    h2 = t.hours % 10;
    if (t.day < 10)
    {
        output << "0" << t.day << "~" << h1 << h2 << ":" << m1 << m2 << ":" << s1 << s2;
    }
    else
    {
        output << t.day << "~" << h1 << h2 << ":" << m1 << m2 << ":" << s1 << s2;
    }
    return output;
}

istream &operator>>(istream &input, Time &t) //輸入，且轉成正確時間表示
{
    input >> t.in;
    int len = (t.in).length();
    char tempstr[4][10000];
    int j = 0;
    int k = 0;
    int check = 0;
    int neg = 0;
    int first = 0;
    for (int i = 0; i < len; i++) //字串切割，分成day hours minutes seconds
    {
        if (t.in[i] == '~' || t.in[i] == ':')
        {
            if (t.in[i] == '~')
            {
                if (first != 0)
                { //如果第一個符號不是～就輸入錯誤
                    check = 2;
                    break;
                }
                check++;
            }
            first = 1;
            tempstr[j][k] = '\0'; //手動設置結尾符
            j++;
            k = 0;
        }
        else
        {
            tempstr[j][k] = t.in[i];
            k++;
        }
        if (t.in[i] == '-') //如果輸入有負號，就全部初始為00~00:00:00
        {
            neg = 1;
        }
    }
    if (j >= 4 || check != 1)
    {
        printf("輸入錯誤\n");
        return input;
    }
    tempstr[j][k] = '\0';     //手動設置結尾符
    t.day = atoi(tempstr[0]); //將字串轉整數型態
    t.hours = atoi(tempstr[1]);
    t.minutes = atoi(tempstr[2]);
    t.seconds = atoi(tempstr[3]);
    //將全部轉成seconds
    int se = t.seconds;
    se += t.day * 24 * 60 * 60;
    se += t.hours * 60 * 60;
    se += t.minutes * 60;
    //轉成正確時間表示
    t.seconds = se % 60;
    t.minutes = ((se / 60) % 60);
    t.hours = (((se / 60) / 60) % 24);
    t.day = (((se / 60) / 60) / 24);
    if (neg == 1)
    { //如果輸入有負號，就全部初始為00~00:00:00
        t.day = t.hours = t.minutes = t.seconds = 0;
    }
    return input;
}

Time Time::operator+(const Time &t) //兩個class Time相加，並轉成正確時間表示
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    int total = seconds1 + seconds2;
    Time t3(total);
    return t3;
}

Time Time::operator-(const Time &t) //兩個class Time相減，並轉成正確時間表示
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    int total = seconds1 - seconds2;
    Time t3(total);
    return t3;
}

//比較兩個class Time
BOOL Time::operator<(const Time &t)
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    if (seconds1 < seconds2)
    {
        return TRUE;
    }
    return FALSE;
}

BOOL Time::operator>(const Time &t)
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    if (seconds1 > seconds2)
    {
        return TRUE;
    }
    return FALSE;
}

BOOL Time::operator<=(const Time &t)
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    if (seconds1 <= seconds2)
    {
        return TRUE;
    }
    return FALSE;
}

BOOL Time::operator>=(const Time &t)
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    if (seconds1 >= seconds2)
    {
        return TRUE;
    }
    return FALSE;
}

BOOL Time::operator==(const Time &t)
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    if (seconds1 == seconds2)
    {
        return TRUE;
    }
    return FALSE;
}

BOOL Time::operator!=(const Time &t)
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = convert_s(t.day, t.hours, t.minutes, t.seconds);
    if (seconds1 != seconds2)
    {
        return TRUE;
    }
    return FALSE;
}

Time Time::operator+(int right) //一個class Time加一整數，且轉成正確時間表示
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = right;
    int total = seconds1 + seconds2;
    Time t3(total);
    return t3;
}

Time Time::operator-(int right) //一個class Time減一整數，且轉成正確時間表示
{
    int seconds1 = 0;
    seconds1 = convert_s(this->day, this->hours, this->minutes, this->seconds);
    int seconds2 = 0;
    seconds2 = right;
    int total = seconds1 - seconds2;
    Time t3(total);
    return t3;
}

Time Time::operator++() // prefix++，且要注意加一後可能不是正確時間表示，要轉成正確表示
{
    seconds++;
    int se = seconds;
    se += day * 24 * 60 * 60;
    se += hours * 60 * 60;
    se += minutes * 60;
    seconds = se % 60;
    minutes = ((se / 60) % 60);
    hours = (((se / 60) / 60) % 24);
    day = (((se / 60) / 60) / 24);
    return *this;
}

const Time Time::operator++(int x) // postfix++，且要注意加一後可能不是正確時間表示，要轉成正確表示
{
    Time temp = *this;
    seconds++;
    int se = seconds;
    se += day * 24 * 60 * 60;
    se += hours * 60 * 60;
    se += minutes * 60;
    seconds = se % 60;
    minutes = ((se / 60) % 60);
    hours = (((se / 60) / 60) % 24);
    day = (((se / 60) / 60) / 24);
    return temp;
}

Time Time::operator--() // prefix--，且要注意減一後可能為負數，要初始化為00~00:00:00
{
    int se = seconds;
    se += day * 24 * 60 * 60;
    se += hours * 60 * 60;
    se += minutes * 60;
    se--;
    if (se < 0)
    {
        day = hours = minutes = seconds = 0;
    }
    else
    {
        seconds = se % 60;
        minutes = ((se / 60) % 60);
        hours = (((se / 60) / 60) % 24);
        day = (((se / 60) / 60) / 24);
    }
    return *this;
}

const Time Time::operator--(int x) // postfix--，且要注意減一後可能為負數，要初始化為00~00:00:00
{
    Time temp = *this;
    int se = seconds;
    se += day * 24 * 60 * 60;
    se += hours * 60 * 60;
    se += minutes * 60;
    se--;
    if (se < 0)
    {
        day = hours = minutes = seconds = 0;
    }
    else
    {
        seconds = se % 60;
        minutes = ((se / 60) % 60);
        hours = (((se / 60) / 60) % 24);
        day = (((se / 60) / 60) / 24);
    }
    return temp;
}

Time operator+(int left, const Time &t) //一整數加一個class Time，且轉成正確時間表示
{
    int seconds1 = left;
    int seconds2 = t.seconds;
    seconds2 += t.day * 24 * 60 * 60;
    seconds2 += t.hours * 60 * 60;
    seconds2 += t.minutes * 60;
    int total = seconds1 + seconds2;
    Time t3(total);
    return t3;
}

Time operator-(int left, const Time &t) //一整數減一個class Time，且轉成正確時間表示
{
    int seconds1 = left;
    int seconds2 = t.seconds;
    seconds2 += t.day * 24 * 60 * 60;
    seconds2 += t.hours * 60 * 60;
    seconds2 += t.minutes * 60;
    int total = seconds1 - seconds2;
    Time t3(total);
    return t3;
}
