#include<iostream>
#include<iomanip>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct LNode
{//图书信息表的链式存储结构
    Book data;    	   //结点的数据域
    int length;       //链表的表长，即图书表中图书个数
    struct LNode *next; //指针域
}LNode,*LinkList;
int Insert_L(LinkList &L)
{//将新图书入库并输出
	LNode*p = L->next;
	int loc; cin >> loc;
	if(loc < 1 || loc > L->length)
		cout << "Sorry，the position to be inserted is invalid!" << endl;
	else
	{
		LNode* t = new LNode;
		cin >> t->data.no >> t->data.name >> t->data.price;
		for(int i = 1; i < loc - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
		L->length++;
		LNode*i = L->next;
		while(i)
		{
			cout << i->data.no << " " << i->data.name << " ";
			printf("%.2f\n", i->data.price);			
			i = i->next;
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
int  Length_L(LinkList &L)
{//求链表的表长，即图书表中图书个数
    LinkList p=L;                 //初始化p指向链表的头结点
    L->length=0;                  //初始化链表的表长L->length为0
    while(p->next)                //下一个结点存在时
    {
        L->length++;              //链表的表长+1
        p=p->next;                //更新指针p，指向下一个结点
    }
    return OK;
}

int main()
{
    LinkList L;                         //定义一个LinkList类型的变量L
    InitList_L(L);                    	//初始化一个空的链表L
    Input_L(L);                        	//输入链表数据
    Length_L(L);                    	//求链表的表长
    Insert_L(L);                    	//将新图书入库并输出
    return 0;
}
