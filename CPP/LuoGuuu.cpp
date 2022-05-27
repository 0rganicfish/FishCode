#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ull unsigned ll
#define QAQ std
#define PLL pair<ll, ll>
#define all(s) s.begin(), s.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace QAQ;

struct node
{
    //链表的节点
    int data;          //数据
    int num;           //节点编号
    struct node *next; //指向下一个节点
};

int main()
{
    struct node *head /*头节点*/, *p, *q;
    head = NULL, p = NULL;
    q = new node;
    q->next = NULL, q->num = 1;

    int a = -1;
    cout << "请输入第1个数字:";
    cin >> a;
    q->data = a;
    head = q;
    while (a)
    {
        p = q;
        q = new node;
        q->next = NULL;
        p->next = q;
        q->num = p->num + 1;
        cout << "请输入第" << q->num << "个数字:";
        cin >> a;
        q->data = a;
    }

    //前面都是输入,这以下都是输出

    q = head;
    p = NULL;
    while (q->data != 0)
    {
        printf("%d %d\n", q->num, q->data);
        q = q->next;
    }

    //释放内存

    q = head;
    p = q;
    while (q->next != NULL)
    {
        p = q->next;
        delete[] q;
        q = p;
    }
    return 0;
}