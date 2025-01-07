#include<iostream>
using namespace std;
typedef struct DuLNode
{
	int data;
	struct DuLNode* next;
	struct DuLNode* prior;
}DuLNode, * DuLinkList;
void CreateList(DuLinkList& L, int n)
{//建立双向循环链表
	L = new DuLNode;
	L->next = L;
	L->prior = L;
	DuLNode* p = L;
	for(int i = 0; i < n; i++)
	{
		DuLNode* t = new DuLNode;
		cin >> t->data;
		p->next = t;
		t->prior = p;
		t->next = L;
		L->prior = t;
		p = p->next;
	}
}
void Exchange(DuLinkList& L, int loc)
{//双向循环链表中结点的交换
	DuLNode* p = L;
	for(int i = 0; i < loc; i++)
		p = p->next;
	int t = p->prior->data;
	p->prior->data = p->data;
	p->data = t;
}

void PrintList(DuLinkList &L)
{//依次输出链表中的数据
    DuLinkList p=L->next;
	while(p->next&&p->next!=L)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
	 	if(n==0) break;
	 	DuLinkList L;
	 	CreateList(L,n);
	 	int loc;
		cin>>loc;
		if(n==1)          //链表仅有一个元素时输出其自身
		{
			cout<<L->next->data<<endl;
			continue;
		}
		Exchange(L,loc);
		PrintList(L);
	}
	return 0;
}
