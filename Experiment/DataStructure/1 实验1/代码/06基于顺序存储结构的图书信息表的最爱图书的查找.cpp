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

int FindFavorite_Sq(SqList L)
{//最爱图书的查找并输出数据
	if(L.length == 0) return ERROR;
	int num; cin >> num;
	while(num)
	{
		bool find = false;
		char b[50];
		cin >> b;
		int n = 0;
		for(int i = 0; i < L.length; i++)
		{
			if(strcmp(b, L.elem[i].name) == 0)
			{
				find = true;
				n++;
			}
		}
		if(n != 0)
			cout << n << endl;
		for(int i = 0; i < L.length; i++)
		{
			if(strcmp(b, L.elem[i].name) == 0)
			{
				cout << L.elem[i].no << " " << L.elem[i].name << " ";
				printf("%.2f\n", L.elem[i].price);
			}
		}
		if(!find)
			cout << "Sorry，there is no your favourite!" << endl;
		num--;
	}
	return OK;
}

int InitList_Sq(SqList &L)
{//构造一个空的顺序表L
    L.elem=new Book[MAXSIZE];     //为顺序表分配一个大小为MAXSIZE的数组空间
    if(!L.elem)exit(OVERFLOW);    //存储分配失败退出
    L.length=0;                   //空表长度为0
    return OK;
}
int Input_Sq(SqList &L)
{//顺序表的输入
    int n;
    cin>>n;    //图书数目n
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;
        L.length++;
    }
    return OK;
}
int main()
{
    SqList L;              //定义一个SqList类型的变量L
    InitList_Sq(L);        //初始化一个空的顺序表L
    Input_Sq(L);           //输入数据
    FindFavorite_Sq(L);    //最爱图书的查找并输出数据
    return 0;
}
