#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//��巨����������
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
void Intersection(LinkList& LA, LinkList& LB)
{//�����������������ϵĽ���    �����LA
	LNode *p1 = LA->next, *p2 = LB->next;
	LinkList LC; LC = LA; LNode *p3 = LC;
	while(p1 && p2)
	{
		if(p1->data < p2->data)
		{
			p1 = p1->next;
		}
		else if(p1->data > p2->data)
		{
			p2 = p2->next;
		}
		else
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	p3->next = NULL;
	delete LB;
}

void PrintList(LinkList &L)
{//��ӡ������������е�����
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
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList LA,LB;
        CreateList_R(LA,n);
        CreateList_R(LB,m);
        Intersection(LA,LB);
        PrintList(LA);
    }
    return 0;
}
