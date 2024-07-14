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
void DeleteEqualNode(LinkList& L, int n)
{//删除链表中绝对值相等的结点
	LNode* p = L->next;
	LinkList LA = new LNode;
	LA->next = NULL;
	LNode *p1 = LA;
	int *a = new int[10000];
	for(int i = 0; i < 10000; i++)
		a[i] = 0;
	for(int i = 0; i < n; i++)
	{
		a[abs(p->data)] = 1;
		p = p->next;
	}
	p = L;
	while(p->next)
	{
		if(a[abs(p->next->data)] == 1)
		{
			a[abs(p->next->data)] = 0;
			p1->next = p->next;
			p1 = p1->next;
		}
		p = p->next;
	}	
	p1->next = NULL;
	L = LA;
}

void PrintList(LinkList &L)
{//打印依次输出链表中的数据
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
        LinkList L;
        CreateList_R(L,n);
        DeleteEqualNode(L,n);
        PrintList(L);
    }
    return 0;
}
