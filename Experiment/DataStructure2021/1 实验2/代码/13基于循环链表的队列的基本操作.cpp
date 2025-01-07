#include<iostream>
using namespace std;
typedef int Status;
typedef struct QNode
{//���е���ʽ�洢�ṹ
    int data;
    struct QNode* next;
}QNode, * QueuePtr;
typedef struct
{
    QueuePtr rear;    //ֻ��һ����βָ��
}LinkQueue;
Status EmptyQueue(LinkQueue Q)
{//�ж϶����Ƿ�Ϊ�գ��շ���1�����򷵻�0
//����ֻ��һ��ͷ��㣬����ͷ����ָ����ָ���Լ�ʱ������Ϊ��
	if(Q.rear->next->next == Q.rear->next)
		return 1;
	return 0;
}
void EnQueue(LinkQueue& Q, int e)
{//��ӣ�����Ԫ��eΪQ���µĶ�βԪ��
	QNode* p = new QNode;
	p->data = e;
	p->next = Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;
}
void DeQueue(LinkQueue& Q)
{//���ӣ����Q�Ķ�ͷԪ��ֵ������ɾ��
	QNode* t = Q.rear->next->next;
	cout << t->data << " ";
	Q.rear->next->next = t->next;
	if(Q.rear == t)
		Q.rear = Q.rear->next->next;
	delete t;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		LinkQueue Q;           //��ʼ��һ����ͷ����ѭ������
		Q.rear=new QNode;
        Q.rear->next=Q.rear;
		while(n--)
		{//n��Ԫ�����
			int e;cin>>e;
			EnQueue(Q,e);
		}
		while(m--)            //m��Ԫ�س���
			DeQueue(Q);
		if(EmptyQueue(Q))
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
	return 0;
}
