#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//��Ҫ�߼� �û����� -������
//�洢�û����� ���ö�Ӧ3*3��һ�����̵ľŸ����ݵ�
//ÿ������һ��x,y��Ӧ�����е�һ�������ӵ�λ��
struct point
{
    int x, y;
    char val;
};
char map[14][14];
struct point data[4][4]; //����Ÿ������ӵ�λ��
//�жϵ�ǰ�û��ߵ�λ���Ƿ�Ϸ�
int isIllegal(int x, int y)
{
    if (x < 1 || x > 13 || y < 1 || y > 13)
        return 1;
    if (data[x][y].val != ' ')
        return 1;
    return 0;
}
//�ж��Ƿ�ʤ�� ����1����XӮ����2����OӮ
int isWin()
{
    int i, j, x = 0, o = 0; //��ͳ��
    int X1 = 0, o1 = 0;     //��ͳ��
    int X11 = 0, o11 = 0;   //�Խ���ͳ��
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
//��ʼ����ͼΪȫ��Ϊ�ո�
void initMap(char data)
{
    int i, j;
    for (i = 1; i <= 13; i++)
        for (j = 1; j <= 13; j++)
            map[i][j] = ' ';
}
//��ʼ�� ��������Ȼ��ÿһ����Ӷ��ǿո�
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
//�����û���������ݸı����̣��ڶ�Ӧ��λ����д���ݣ�
void changeMap()
{
    int i, j;
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
            map[data[i][j].x][data[i][j].y] = data[i][j].val;
}
//��ӡ����
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
//���ݶ�Ӧ�����λ�ã�1��2��3.����9��ת�����û����ݵĵڼ���
int getHang(int n)
{
    if (n >= 1 && n <= 3)
        return 1;
    if (n >= 4 && n <= 6)
        return 2;
    if (n >= 7 && n <= 9)
        return 3;
}
//ͬ�� ת���ɵڼ���
int getLie(int n)
{
    return n % 3 == 0 ? 3 : n % 3;
}
int main()
{

    char man[3] = {'0', 'X', 'O'};
    //��ʼ��1��ΪX����ΪO
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
    //������ܷžŸ����ӡ�
    while (count <= 9)
    {

        printf("%c����\n", man[count % 2 == 0 ? 2 : 1]);
        scanf("%d", &pos);
        system("cls");
        x = getHang(pos);
        y = getLie(pos);
        if (isIllegal(x, y))
        {
            count--;
            printf("����Ƿ� ����������\n");
        }

        else
            data[x][y].val = man[count % 2 == 0 ? 2 : 1];
        changeMap();
        printMap();

        int winer = isWin(); //�ж���˭Ӯ��
        if (winer == 1)
        {
            printf("Xʤ\n");
            break;
        }
        else if (winer == 2)
        {
            printf("Oʤ\n");
            break;
        }
        count++;
    }
    if (count == 9)
        printf("ƽ��\n");
    return 0;
}