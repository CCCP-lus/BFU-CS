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
double GetAverage(LinkList L, int n)
{//�ݹ���ⵥ�����е�ƽ��ֵ
	if(!L->next)
		return L->data;
	return (GetAverage(L->next, n - 1) * (n - 1) + L->data) / n;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L;
        CreateList_R(L,n);
        L=L->next;//Lָ����Ԫ���
        printf("%.2f\n",GetAverage(L,n));//���������λС��
    }
    return 0;
}
