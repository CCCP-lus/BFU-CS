#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
	L = new LNode;
	L->next = NULL;
	int num = n;
	LNode* p = L;
	while(num--)
	{
		LNode* t = new LNode;
		cin >> t->data;
		t->next = NULL;
		p->next = t;
		p = t;
	}
}
void Decollate(LinkList &L, LinkList &L1)
{//奇偶链表的分割
	LNode *p1 = L, *p2 = L1;
	bool odd = true;
	while(p1->next)
	{
		if(!odd)
		{
			p1 = p1->next;
		}
		else
		{
			p2->next = p1->next;
			p2 = p2->next;
			p1->next = p1->next->next;
		}
		odd = !odd;
	}
	p2->next = L->next;
	p1->next = NULL;
}

void PrintList(LinkList L)
{//依次输出链表中的数据
    LinkList p = L->next;
    while (p)
    {
        if (p->next != NULL) cout << p->data << " ";
        else cout << p->data;
        p = p->next;
    }
    cout << endl;
}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		LinkList L=new LNode;
        CreateList_R(L,n);
        LinkList L1=new LNode;    //申请新链表L1
        L1->next=NULL;
        Decollate(L,L1);      //奇偶链表的分割
        PrintList(L1);
	}
	return 0;
}
