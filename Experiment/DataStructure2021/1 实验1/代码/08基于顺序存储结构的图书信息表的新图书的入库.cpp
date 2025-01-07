#include<iostream>
#include <string.h>
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

int Insert_Sq(SqList &L)
{//新图书的入库和输出
    if(L.length == 0) return ERROR;
    int loc; cin >> loc;
    if(loc < 1 || loc > L.length + 1)
    	cout << "Sorry，the position to be inserted is invalid!" << endl;
    else
    {
		for(int i = L.length - 1; i >= loc - 1; i--)
		{
			L.elem[i + 1] = L.elem[i];
		}
		cin >> L.elem[loc - 1].no >> L.elem[loc - 1].name >>L.elem[loc - 1].price;
		L.length++;
		for(int i = 0; i < L.length; i++)
		{
			cout << L.elem[i].no << " " << L.elem[i].name << " ";
			printf("%.2f\n", L.elem[i].price);
		}
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
    SqList L;           //定义一个SqList类型的变量L
    InitList_Sq(L);     //初始化一个空的顺序表L
    Input_Sq(L);        //输入数据
    Insert_Sq(L);	//新图书的入库和输出
    return 0;
}



