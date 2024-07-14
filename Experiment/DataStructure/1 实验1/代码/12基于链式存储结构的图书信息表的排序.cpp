#include<iostream>
#include<string.h>
#include<iomanip>
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

int Sort_L(LinkList &L)
{//将图书按照价格降序排序
    LNode *head = L, *p1, *prep1, *p2, *prep2, *temp;
    prep1 = L->next;
    p1 = prep1->next;
    bool flag;
    while(p1)
    {
		flag = true;
		temp = p1;
		for(prep2 = head, p2 = prep2->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{
			if(p2->data.price < p1->data.price)
			{
				p1 = p1->next;
				prep1->next = p1;
				prep2->next = temp;
				temp->next = p2;
				flag = false;
				break;
			}
		}	
		if(flag)
		{
			prep1 = prep1->next;
			p1 = p1->next;
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
    LinkList p=L;    //初始化p指向链表的头结点
    char no[20];
    char name[50];
    float price;
    while(cin>>no>>name>>price)
    {
        if(strcmp(no,"0")==0&&strcmp(name,"0")==0&&price==0)//输入结束标志
            break;
        else
        {//后插法创建单链表
            LinkList q=new LNode;       //生成新结点*q
            strcpy(q->data.no, no);      //将结点*q数据域的no部分置为no
            strcpy(q->data.name, name);  //将结点*q数据域的name部分置为name
            q->data.price=price;        //将结点*q数据域的price部分置为price
            q->next=NULL;               //尾指针置为NULL
            p->next=q;                 //将新结点*q插入尾结点*p之后
            p=q;                       //更新p，将p指向新的尾结点*q
        }
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
int Output_L(LinkList L)
{//链表的输出
    LinkList p=L;		//初始化p指向链表的头结点
    while(p->next)  //下一个结点存在时
    {
        cout<<p->next->data.no<<" "<<p->next->data.name<<" "<<fixed<<setprecision(2)<<p->next->data.price<<endl;
        p=p->next;   //更新指针p，指向下一个结点
    }
    return OK;
}

int main()
{
    LinkList L;                	//定义一个LinkList类型的变量L
    InitList_L(L);            	//初始化一个空的链表L
    Input_L(L);                	//输入数据
    Length_L(L);            	//先求链表L的表长L->length
    Sort_L(L);                	//降序排序
    Output_L(L);            	//输出链表
    return 0;
}
