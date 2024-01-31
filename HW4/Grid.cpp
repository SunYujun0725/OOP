#include <iostream>
#include <cstring>
#include <cstdlib> //srand rand
#include <ctime>

#include "Grid.h"

using namespace std;

char grid[40][40];
char temp_mover[0][0]; //暫時放mover的地方
int Tog = 0;           //判斷ON OFF狀態的變數，偶數為ON，奇數為OFF
int item_mover = 0;
int exit_x; //出口的row位置
int exit_y; //出口的col位置
int Wall_x;

Grid::Grid()
{
    for (int i = 0; i < 40; i++)
    { //全部初始化為x
        for (int j = 0; j < 40; j++)
        {
            grid[i][j] = 'x';
        }
    }
    grid[0][0] = '<';
}
Grid::Grid(int r, int c)
{ //建構函式（創造一個r*c的二維陣列）

    Tog = 0;
    temp_mover[0][0] = 'x';
    if (r < 3)
    {
        r = 3;
    }
    else if (c < 3)
    {
        c = 3;
    }
    else if (r > 40)
    {
        r = 40;
    }
    else if (c > 40)
    {
        c = 40;
    }
    for (int i = 0; i < 40; i++)
    { //全部初始化為x
        for (int j = 0; j < 40; j++)
        {
            grid[i][j] = 'x';
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
            { //建立圍牆
                grid[i][j] = '#';
            }
            else
            {
                grid[i][j] = '.';
            }
        }
    }
    int x = 0;
    x = RandWall(); //產生隨機要離開的出口牆
    int y = 0;

    if (x == 1)
    {
        y = RandPoint(c);
        grid[0][y] = '.';
        exit_x = 0;
        exit_y = y;
        Wall_x = x;
    }
    else if (x == 2)
    {
        y = RandPoint(r);
        grid[y][c - 1] = '.';
        exit_x = y;
        exit_y = c - 1;
        Wall_x = x;
    }
    else if (x == 3)
    {
        y = RandPoint(c);
        grid[r - 1][y] = '.';
        exit_x = r - 1;
        exit_y = y;
        Wall_x = x;
    }
    else if (x == 4)
    {
        y = RandPoint(r);
        grid[y][0] = '.';
        exit_x = y;
        exit_y = 0;
        Wall_x = x;
    }
    int mover_x = RandPoint(r); //隨機產生mover位置
    int mover_y = RandPoint(c);
    int mover_d = RandWall(); //隨機產生mover方向
    if (mover_d == 1)
    { //上
        grid[mover_x][mover_y] = '^';
    }
    else if (mover_d == 2)
    { //下
        grid[mover_x][mover_y] = 'v';
    }
    else if (mover_d == 3)
    { //左
        grid[mover_x][mover_y] = '<';
    }
    else if (mover_d == 4)
    { //右
        grid[mover_x][mover_y] = '>';
    }
}
Grid::Grid(int r, int c, int mr, int mc, int d)
{
    Tog = 0;
    temp_mover[0][0] = 'x';
    if (r < 3)
    {
        r = 3;
    }
    else if (c < 3)
    {
        c = 3;
    }
    else if (r > 40)
    {
        r = 40;
    }
    else if (c > 40)
    {
        c = 40;
    }

    for (int i = 0; i < 40; i++)
    { //全部初始化為x
        for (int j = 0; j < 40; j++)
        {
            grid[i][j] = 'x';
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
            { //建立圍牆
                grid[i][j] = '#';
            }
            else if (i == mr && j == mc) //放mover
            {
                if (d == 0)
                { //北
                    grid[i][j] = '^';
                }
                else if (d == 1)
                { //西
                    grid[i][j] = '<';
                }
                else if (d == 2)
                { //南
                    grid[i][j] = 'v';
                }
                else
                { //東
                    grid[i][j] = '>';
                }
            }
            else
            {
                grid[i][j] = '.';
            }
        }
    }
    int x = 0;
    x = RandWall(); //產生隨機要離開的出口牆
    int y = 0;

    if (x == 1)
    {
        y = RandPoint(c);
        grid[0][y] = '.';
        exit_x = 0;
        exit_y = y;
        Wall_x = x;
    }
    else if (x == 2)
    {
        y = RandPoint(r);
        grid[y][c - 1] = '.';
        exit_x = y;
        exit_y = c - 1;
        Wall_x = x;
    }
    else if (x == 3)
    {
        y = RandPoint(c);
        grid[r - 1][y] = '.';
        exit_x = r - 1;
        exit_y = y;
        Wall_x = x;
    }
    else if (x == 4)
    {
        y = RandPoint(r);
        grid[y][0] = '.';
        exit_x = y;
        exit_y = 0;
        Wall_x = x;
    }
}
int Grid::RandWall()
{
    srand(time(NULL));
    //指定亂數範圍
    int min = 1;
    int max = 4;
    int x = rand() % (max - min + 1) + min; //產生 [min , max] 的整數亂數
    return x;
}
int Grid::RandPoint(int rang)
{

    srand(time(NULL));

    //指定亂數範圍
    int min = 1;
    int max = rang - 2;

    int y = rand() % (max - min + 1) + min; //產生 [min , max] 的整數亂數

    return y;
}
bool Grid::Move(int s) //往當時方向前進s格
{
    if (item_mover == 0)
    {
        int mr = GetRow();
        int mc = GetCol();
        if (grid[mr][mc] == '^')
        {                                //往北
            for (int i = 1; i <= s; i++) //先判斷是否可以走到底
            {
                if (grid[mr - i][mc] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = ' '; //將原地改空格
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr - i][mc] != '0')
                {
                    grid[mr - i][mc] = '^';
                }
                else if (i == s && grid[mr - i][mc] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr - i][mc] = ' '; // 預設為ON
                }
            }
            return TRUE;
        }
        else if (grid[mr][mc] == 'v')
        { //往南
            for (int i = 1; i <= s; i++)
            {
                if (grid[mr + i][mc] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = ' '; //將原地改空格
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr + i][mc] != '0')
                {
                    grid[mr + i][mc] = 'v';
                }
                else if (i == s && grid[mr + i][mc] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr + i][mc] = ' '; // 預設為ON
                }
            }
            return TRUE;
        }
        else if (grid[mr][mc] == '<')
        { //往西
            for (int i = 1; i <= s; i++)
            {
                if (grid[mr][mc - i] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = ' '; //將原地改空格
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr][mc - i] != '0')
                {
                    grid[mr][mc - i] = '<';
                }
                else if (i == s && grid[mr][mc - i] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr][mc - i] = ' '; // 預設為ON
                }
            }
            return TRUE;
        }
        else if (grid[mr][mc] == '>')
        { //往東
            for (int i = 1; i <= s; i++)
            {
                if (grid[mr][mc + i] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = ' '; //將原地改空格
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr][mc + i] != '0')
                {
                    grid[mr][mc + i] = '>';
                }
                else if (i == s && grid[mr][mc + i] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr][mc + i] = ' '; // 預設為ON
                }
            }
            return TRUE;
        }
    }
    else
    { // itme與mover重疊
        int mr = GetRow();
        int mc = GetCol();
        if (temp_mover[0][0] == '^')
        {                                //往北
            for (int i = 1; i <= s; i++) //先判斷是否可以走到底
            {
                if (grid[mr - i][mc] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = '0'; //將原地改item 0
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr - i][mc] != '0')
                {
                    grid[mr - i][mc] = '^';
                }
                else if (i == s && grid[mr - i][mc] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr - i][mc] = ' '; // 預設為ON
                }
            }
            item_mover = 0; //重設為0
            return TRUE;
        }
        else if (temp_mover[0][0] == 'v')
        { //往南
            for (int i = 1; i <= s; i++)
            {
                if (grid[mr + i][mc] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = '0'; //將原地改item 0
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr + i][mc] != '0')
                {
                    grid[mr + i][mc] = 'v';
                }
                else if (i == s && grid[mr + i][mc] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr + i][mc] = ' '; // 預設為ON
                }
            }
            item_mover = 0; //重設為0
            return TRUE;
        }
        else if (temp_mover[0][0] == '<')
        { //往西
            for (int i = 1; i <= s; i++)
            {
                if (grid[mr][mc - i] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = '0'; //將原地改item 0
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr][mc - i] != '0')
                {
                    grid[mr][mc - i] = '<';
                }
                else if (i == s && grid[mr][mc - i] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr][mc - i] = ' '; // 預設為ON
                }
            }
            item_mover = 0; //重設為0
            return TRUE;
        }
        else if (temp_mover[0][0] == '>')
        { //往東
            for (int i = 1; i <= s; i++)
            {
                if (grid[mr][mc + i] == '#')
                {
                    return FALSE;
                }
            }
            grid[mr][mc] = '0'; //將原地改item 0
            for (int i = 1; i <= s; i++)
            {
                if (i == s && grid[mr][mc + i] != '0')
                {
                    grid[mr][mc + i] = '>';
                }
                else if (i == s && grid[mr][mc + i] == '0')
                {
                    temp_mover[0][0] = '^';
                    item_mover = 1;
                    grid[mr - i][mc] = '@';
                }
                else
                {
                    grid[mr][mc + i] = ' '; // 預設為ON
                }
            }
            item_mover = 0; //重設為0
            return TRUE;
        }
    }

    return FALSE;
}
void Grid::TogglePath() //判斷ON OFF
{
    Tog = Tog + 1;
}
void Grid::TurnLeft() //左轉90度
{
    int mr = GetRow();
    int mc = GetCol();
    if (item_mover == 0)
    { // item不再mover上
        if (grid[mr][mc] == '^')
        {
            grid[mr][mc] = '<';
        }
        else if (grid[mr][mc] == 'v')
        {
            grid[mr][mc] = '>';
        }
        else if (grid[mr][mc] == '<')
        {
            grid[mr][mc] = 'v';
        }
        else if (grid[mr][mc] == '>')
        {
            grid[mr][mc] = '^';
        }
    }
    else
    {
        if (temp_mover[0][0] == '^')
        {
            temp_mover[0][0] = '<';
        }
        else if (temp_mover[0][0] == 'v')
        {
            temp_mover[0][0] = '>';
        }
        else if (temp_mover[0][0] == '<')
        {
            temp_mover[0][0] = 'v';
        }
        else if (temp_mover[0][0] == '>')
        {
            temp_mover[0][0] = '^';
        }
    }
}
void Grid::PutDown() //放item(0)在mover當前位置
{
    int r = GetNumRows();
    int c = GetNumCols();
    int mr = GetRow();
    int mc = GetCol();
    temp_mover[0][0] = grid[mr][mc]; //將mover暫放
    item_mover = 1;                  //改1
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == mr && j == mc)
            {
                grid[i][j] = '@';
            }
        }
    }
}
bool Grid::PutDown(int r, int c) // itme要放在（r,c）
{
    int nr = GetNumRows();
    int nc = GetNumCols();
    int mr = GetRow();
    int mc = GetCol();
    if (r == mr && c == mc)
    {
        PutDown();
        return 0;
    }
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            if (i == r && j == c && (grid[i][j] == '.' || grid[i][j] == ' ')) //不在mover上 且只能放.或空白位置
            {
                grid[i][j] = '0';
                return TRUE;
            }
        }
    }
    return FALSE;
}
bool Grid::PickUp() //取item，將它從grid中刪除 將@改mover
{
    int r = GetNumRows();
    int c = GetNumCols();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '@')
            {
                grid[i][j] = temp_mover[0][0];
                item_mover = 0;
                return TRUE;
            }
        }
    }
    return FALSE;
}
bool Grid::PlaceBlock(int r, int c) //放block在（r,c）
{
    int nr = GetNumRows();
    int nc = GetNumCols();
    if (r == exit_x && c == exit_y) // block放在出口位置錯誤
    {
        return FALSE;
    }
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            if (i == r && j == c && (grid[i][j] == '.' || grid[i][j] == ' ')) //只能放在'.'或空白上
            {
                grid[i][j] = '#';
                return TRUE;
            }
        }
    }
    return FALSE;
}
void Grid::Grow(int gr, int gc) // grid大小增加gr行,gc列
{

    int r = GetNumRows();
    int c = GetNumCols();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
            { //將圍牆重設為.
                grid[i][j] = '.';
            }
        }
    }
    int nr; //增加後的大小
    int nc;
    nr = r + gr;
    nc = c + gc;
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            if (i == 0 || j == 0 || i == nr - 1 || j == nc - 1)
            {
                grid[i][j] = '#';
            }
            else if (i >= r || j >= c)
            {
                grid[i][j] = '.';
            }
        }
    }
    if (Wall_x == 2)
    {
        printf("x=2");
        printf("%d %d\n", exit_x, exit_y);
        grid[exit_x][nc - 1] = '.';
    }
    else if (Wall_x == 3)
    {

        grid[nr - 1][exit_y] = '.';
    }
    else
    {
        grid[exit_x][exit_y] = '.';
    }
}
void Grid::Display() const //印出結果
{
    printf("The Grid:\n");
    int r = GetNumRows();
    int c = GetNumCols();
    if (Tog % 2 == 0)
    { // ON
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    { // OFF
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == ' ')
                {
                    cout << "."
                         << " ";
                }
                else
                {
                    cout << grid[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
}
bool Grid::FrontlsClear() const // mover前是否暢通
{
    int mr = GetRow();
    int mc = GetCol();
    if (item_mover == 0)
    { // item不在mover上
        if (grid[mr][mc] == '^')
        {
            if (grid[mr - 1][mc] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (grid[mr][mc] == 'v')
        {
            if (grid[mr + 1][mc] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (grid[mr][mc] == '<')
        {
            if (grid[mr][mc - 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (grid[mr][mc] == '>')
        {
            if (grid[mr][mc + 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
    }
    else
    { // item與mover重疊
        if (temp_mover[0][0] == '^')
        {
            if (grid[mr - 1][mc] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (temp_mover[0][0] == 'v')
        {
            if (grid[mr + 1][mc] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (temp_mover[0][0] == '<')
        {
            if (grid[mr][mc - 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (temp_mover[0][0] == '>')
        {
            if (grid[mr][mc + 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
    }
    return FALSE;
}
bool Grid::RightlsClear() const // mover右側是否暢通
{
    int mr = GetRow();
    int mc = GetCol();
    if (item_mover == 0)
    { // item不在mover上
        if (grid[mr][mc] == '^')
        {
            if (grid[mr][mc + 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (grid[mr][mc] == 'v')
        {
            if (grid[mr][mc - 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (grid[mr][mc] == '<')
        {
            if (grid[mr - 1][mc] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (grid[mr + 1][mc] == '>')
        {
            if (grid[mr][mc + 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
    }
    else
    { // item與mover重疊
        if (temp_mover[0][0] == '^')
        {
            if (grid[mr][mc + 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (temp_mover[0][0] == 'v')
        {
            if (grid[mr][mc - 1] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (temp_mover[0][0] == '<')
        {
            if (grid[mr - 1][mc] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
        else if (temp_mover[0][0] == '>')
        {
            if (grid[mr + 1][mc] == '#')
            { //被擋住了
                return FALSE;
            }
            return TRUE;
        }
    }
    return FALSE;
}
int Grid::GetRow() const //返回目前mover的row
{
    int r = GetNumRows();
    int c = GetNumCols();
    if (item_mover == 0)
    { // item不在mover上
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '>' || grid[i][j] == '<' || grid[i][j] == '^' || grid[i][j] == 'v')
                {
                    return i;
                }
            }
        }
    }
    else
    { // item與mover重疊
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '@')
                {
                    return i;
                }
            }
        }
    }
    printf("ERROR:GetRow\n");
    return 0;
}
int Grid::GetCol() const //返回目前mover的cols
{
    int r = GetNumRows();
    int c = GetNumCols();
    if (item_mover == 0)
    { // item不在mover上
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '>' || grid[i][j] == '<' || grid[i][j] == '^' || grid[i][j] == 'v')
                {
                    return j;
                }
            }
        }
    }
    else
    { // item與mover重疊
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '@')
                {
                    return j;
                }
            }
        }
    }
    printf("ERROR:GetCol\n");
    return 0;
}

int Grid::GetNumRows() const //回傳rows的行數
{
    for (int i = 0; i < 40; i++)
    {
        if (grid[i][0] == 'x')
        {
            return i;
        }
        if (grid[39][0] != 'x')
        {
            return 40;
        }
    }
    printf("ERROR:GetNumRows\n");
    return 0;
}
int Grid::GetNumCols() const //回傳cols的列數
{
    for (int i = 0; i < 40; i++)
    {
        if (grid[0][i] == 'x')
        {
            return i;
        }
        if (grid[0][39] != 'x')
        {
            return 40;
        }
    }
    printf("ERROR:GetNumCols\n");
    return 0;
}
