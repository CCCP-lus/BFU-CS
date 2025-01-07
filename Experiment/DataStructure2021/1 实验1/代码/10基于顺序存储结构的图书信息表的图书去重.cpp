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

int SearchList(SqList L,char no[20])
{//查找书号是否在图书信息表L中
	if(L.length == 0) return ERROR;
	for(int i = 0; i < L.length; i++)
	{
		if(strcmp(no, L.elem[i].no) == 0)
			return OK;
	}
	return ERROR;
}
int DupRemoval_Sq(SqList L1,SqList &L2)
{//图书去重
	int j = 0;
	for(int i = 0; i < L1.length; i++)
	{
		if(!SearchList(L2, L1.elem[i].no))
		{
			L2.length++;
			L2.elem[j] = L1.elem[i];
			j++;
		}
	}
	cout << L2.length << endl;
	for(int i = 0; i < L2.length; i++)
	{
		cout << L2.elem[i].no << " " << L2.elem[i].name << " ";
		printf("%.2f\n", L2.elem[i].price);
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
        L.length++;//图书个数+1
    }
    return OK;
}
int main() {
    SqList L1,L2;            	 //定义SqList类型的变量L1,L2
    InitList_Sq(L1);        	 //初始化一个空的顺序表L1
    InitList_Sq(L2);       	 //初始化一个空的顺序表L2
    Input_Sq(L1);          	 //输入数据到L1
    DupRemoval_Sq(L1,L2);       //图书去重并输出结果
    return 0;
}
