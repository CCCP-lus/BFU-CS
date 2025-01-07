#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //图书表可能达到的最大长度
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct
{//图书表的顺序存储结构类型为SqList
    Book *elem;                   //存储空间的基地址
    int length;                   //图书表中当前图书个数
}SqList;
int InitList_Sq(SqList &L)
{//构造一个空的顺序表L
    L.elem = new Book[MAXSIZE];
    L.length = 0;
    if(L.elem) return OK;
    else return ERROR;
}
int Input_Sq(SqList &L)
{//顺序表的输入
    bool flag = true;
    char a[20], b[20];
	double c;
    while(flag)
    {
        cin >> a >> b >> c;
		if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0 && c == 0)
		{
			flag = false;
			break;
		}
		Book t;
        strcpy(t.no, a);
        strcpy(t.name, b);
        t.price = c;
		L.elem[L.length] = t;
		L.length++;
    }
    return OK;
}
int Output_Sq(SqList L)
{//顺序表的输出
    	cout << L.length << endl;
    for(int i = 0; i < L.length; i++)
    {    
        cout << L.elem[i].no << " " << L.elem[i].name << " ";
        printf("%.2f\n", L.elem[i].price);
    }
	return OK;
}

int main()
{
    SqList L;                   //定义一个SqList类型的变量L
    InitList_Sq(L);             //初始化一个空的顺序表L
    Input_Sq(L);                //输入数据
    Output_Sq(L);               //输出数据
    return 0;
}
