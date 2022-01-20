#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//主要逻辑 用户数据 -》棋盘
//存储用户数据 正好对应3*3的一个棋盘的九个数据点
//每个里面一个x,y对应棋盘中的一个填棋子的位置
struct point
{
    int x, y;
    char val;
};
char map[14][14];
struct point data[4][4]; //代表九个填棋子的位置
//判断当前用户走的位置是否合法
int isIllegal(int x, int y)
{
    if (x < 1 || x > 13 || y < 1 || y > 13)
        return 1;
    if (data[x][y].val != ' ')
        return 1;
    return 0;
}
//判断是否胜利 返回1代表X赢返回2代表O赢
int isWin()
{
    int i, j, x = 0, o = 0; //行统计
    int X1 = 0, o1 = 0;     //列统计
    int X11 = 0, o11 = 0;   //对角线统计
    for (i = 1; i <= 3; i++)
    {
        if (data[i][i].val == 'X')
            X11++;
        if (data[i][i].val == 'O')
            o11++;

        x = 0;
        o = 0;
        X1 = 0;
        o1 = 0;
        for (j = 1; j <= 3; j++)
        {
            if (data[i][j].val == 'X')
                x++;
            else if (data[i][j].val == 'O')
                o++;
            if (data[j][i].val == 'X')
                X1++;
            else if (data[j][i].val == 'O')
                o1++;
        }
        if (x == 3 || X1 == 3 || X11 == 3)
            return 1;
        if (o == 3 || o1 == 3 || o11 == 3)
            return 2;
    }
    if (data[1][3].val == 'X' && data[2][2].val == 'X' && data[3][1].val == 'X')
        return 1;
    if (data[1][3].val == 'O' && data[2][2].val == 'O' && data[3][1].val == 'O')
        return 2;
    return 0;
}
//初始化地图为全部为空格
void initMap(char data)
{
    int i, j;
    for (i = 1; i <= 13; i++)
        for (j = 1; j <= 13; j++)
            map[i][j] = ' ';
}
//初始化 画出棋盘然后每一个棋坑都是空格
void init()
{
    int i, j, count = 1;
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
        {
            data[i][j].x = 3 + (i - 1) * 4;
            data[i][j].y = 3 + (j - 1) * 4;
            data[i][j].val = ' ';
        }
    initMap(' ');
    for (i = 1; i <= 13; i++)
    {
        map[5][i] = '*';
        map[9][i] = '*';
        map[i][5] = '*';
        map[i][9] = '*';
    }
}
//根据用户输入的数据改变棋盘（在对应的位置填写数据）
void changeMap()
{
    int i, j;
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
            map[data[i][j].x][data[i][j].y] = data[i][j].val;
}
//打印棋盘
void printMap()
{
    int i, j;
    for (i = 1; i <= 13; i++)
    {
        for (j = 1; j <= 13; j++)
        {
            if (i == 1 || i == 13)
                continue;
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
//根据对应输入的位置（1，2，3.。。9）转换成用户数据的第几行
int getHang(int n)
{
    if (n >= 1 && n <= 3)
        return 1;
    if (n >= 4 && n <= 6)
        return 2;
    if (n >= 7 && n <= 9)
        return 3;
}
//同上 转化成第几列
int getLie(int n)
{
    return n % 3 == 0 ? 3 : n % 3;
}
int main()
{

    char man[3] = {'0', 'X', 'O'};
    //初始化1号为X二号为O
    printf("Game Start\n");
    init();
    printf("Please select the first one to play the chess\n[X/O]");
    char c;
    scanf("%c", &c);
    int count = 1;
    if (c == 'O')
    {
        man[0] = man[1];
        man[1] = man[2];
        man[2] = man[0];
    }
    int pos;
    int x, y;
    //顶多就能放九个棋子。
    while (count <= 9)
    {

        printf("%c走棋\n", man[count % 2 == 0 ? 2 : 1]);
        scanf("%d", &pos);
        system("cls");
        x = getHang(pos);
        y = getLie(pos);
        if (isIllegal(x, y))
        {
            count--;
            printf("输入非法 请重新输入\n");
        }

        else
            data[x][y].val = man[count % 2 == 0 ? 2 : 1];
        changeMap();
        printMap();

        int winer = isWin(); //判断是谁赢了
        if (winer == 1)
        {
            printf("X胜\n");
            break;
        }
        else if (winer == 2)
        {
            printf("O胜\n");
            break;
        }
        count++;
    }
    if (count == 9)
        printf("平局\n");
    return 0;
}