#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;

void CreateList_R(LinkList& L, int n)
{
    // 尾插法
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

void Inverse(LinkList& L)
{//逆置带头结点的单链表L
    LNode*p = L;
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
}

void PrintList(LinkList &L)
{
    L=L->next;
    while(L){
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L=new LNode;
        CreateList_R(L,n);
        Inverse(L);
        PrintList(L);
    }
    return 0;
}
