#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000                                  //图书表可能达到的最大长度
using namespace std;
typedef struct
{//图书信息定义
    char no[20];                                        //图书ISBN
    char name[60];                                     //图书名字
    float price;                                       //图书价格
}Book;
typedef struct
{//图书表的顺序存储结构类型为SqList
    Book *elem;                                         //存储空间的基地址
    int length;                                        //图书表中当前图书个数
}SqList;

int Input_Sq(SqList &L)
{//顺序表的输入
    int num; cin >> num;
    if(L.length) return ERROR;
    for(int i = 0; i < num; i++)
   	{
        cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
        L.length++;
    }
    Book t;
    for(int i = 0; i < L.length / 2; i++)
    {
   		
   		t = L.elem[i];
   		L.elem[i] = L.elem[L.length - i - 1];
   		L.elem[L.length - i - 1] = t;
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

int Output_Sq(SqList L)
{//顺序表的输出
    for(int i=0;i<L.length;i++) //图书的信息（书号、书名、价格）
        cout<<L.elem[i].no<<" "<< L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
    return OK;
}

int main()
{
    SqList L;                                           //定义一个SqList类型的变量L
    InitList_Sq(L);                                    //初始化一个空的顺序表L
    Input_Sq(L);                                       //逆序存储输入数据
    Output_Sq(L);                                      //输出数据
    return 0;
} 
