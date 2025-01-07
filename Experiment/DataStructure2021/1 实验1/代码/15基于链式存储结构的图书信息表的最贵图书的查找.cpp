#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//图书信息定义
    char no[20];     //图书ISBN
    char name[50];   //图书名字
    float price;     //图书价格
}Book;
typedef struct LNode
{//图书信息表的链式存储结构
    Book data;    	   //结点的数据域
    int length;       //链表的表长，即图书表中图书个数
    struct LNode *next; //指针域
}LNode,*LinkList;
int HighestPrice_L(LinkList L)
{//查找价格最高的图书
   LNode* p = L->next;
   float max = -1; int num = 0;
   for(p = L->next; p != NULL; p = p->next)
   {
   		if(p->data.price > max)
   		{
		   	max = p->data.price;
		   	num = 1;
		}
		else if(p->data.price == max)
		{
			num++;
		}
   }
   cout << num << endl;
   for(p = L->next; p != NULL; p = p->next)
   {
		if(p->data.price == max)
		{
			cout << p->data.no << " " << p->data.name << " ";
			printf("%.2f\n", p->data.price);
		}
   }
   return OK;
}

int InitList_L(LinkList &L)
{//构造一个空的单链表L
    L=new LNode;
    L->next=NULL;
    return OK;
}
int Input_L(LinkList &L)
{//链表的输入
    LinkList p=L;      //初始化p指向链表的头结点
    int n;
    cin>>n;
    while(n--)             	     //后插法创建链表
    {
        LinkList q=new LNode;        //生成新结点*q
        cin>>q->data.no>>q->data.name>>q->data.price;//输入数据
        q->next=NULL;                                 //尾指针置为NULL
        p->next=q;                   //将新结点*q插入尾结点*p之后
        p=q;                         //更新指针p，将p指向新的尾结点*q
    }
    return OK;
}

int main() {
    LinkList L;                      //定义一个LinkList类型的变量L
    InitList_L(L);                   //初始化一个空的链表L
    Input_L(L);                      //输入链表数据
    HighestPrice_L(L);               //查找价格最高的图书并输出相关信息
    return 0;
}


