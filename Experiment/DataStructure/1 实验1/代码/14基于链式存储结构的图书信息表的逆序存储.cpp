#include<iostream>
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
int Input_L(LinkList &L)
{//链表的输入
    int n; cin >> n;
    LNode* p = L;
	for(int i = 0; i < n; i++)
	{
		LNode* t = new LNode;
		t->next = NULL;
		cin >> t->data.no >> t->data.name >> t->data.price;
		p->next = t;
		p = t;
	}
	p = L;
	LNode* cur = NULL;
    LNode* nxt = NULL;
    cur = p->next->next;
    p->next->next = NULL;
    while(cur != NULL)
    {
		nxt = cur->next;
		cur->next = p->next;
		p->next = cur;
		cur = nxt;
	}
    return OK;
}

int InitList_L(LinkList &L)
{//构造一个空的单链表L
    L=new LNode;
    L->next=NULL;
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

int main(int argc, const char * argv[]) {
    LinkList L;                       //定义一个LinkList类型的变量L
    InitList_L(L);                    //初始化一个空的链表L
    Input_L(L);                       //前插法输入数据
    Output_L(L);                      //输出链表L数据
    return 0;
}
