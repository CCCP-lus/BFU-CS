#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//��巨����������
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
{//�ݹ���ⵥ�����е����ֵ
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
        L=L->next;    //ָ����Ԫ���
        cout<<GetMax(L)<<endl;
    }
    return 0;
}
