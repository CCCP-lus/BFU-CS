#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
    int num = n;
    L = new LNode;
    L->next = NULL;
    LNode* p = L;
    while(num--)
    {
		LNode *t = new LNode;
		cin >> t->data;
		t->next = NULL;
		p->next = t;
		p = t;
	}
}

int GetMax(LinkList L)
{//递归求解单链表中的最大值
	if(!L->next)
		return L->data; 
	return max(GetMax(L->next),L->data);
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L;
        CreateList_R(L,n);
        L=L->next;    //指向首元结点
        cout<<GetMax(L)<<endl;
    }
    return 0;
}
