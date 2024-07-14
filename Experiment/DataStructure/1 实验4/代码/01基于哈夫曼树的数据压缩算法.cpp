#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef struct
{//��������������ʽ
	int weight;               //����Ȩֵ
	int parent,lchild,rchild;  //����˫�ס����ӡ��Һ��ӵ��±�
}HTNode,*HuffmanTree;       //��̬��������洢��������
typedef char **HuffmanCode;   //������������
int Search(char a[],char ch)
{//�����������ַ�ch���ڵ�λ�ã����������±꣬���򷵻�-1
	int flag = -1;
	for(int i = 0; i < (int)strlen(a); i++)
	{
		if(a[i] == ch)
		{
			flag = i;
			break;
		}
	}
	return flag;
}
void Sort(char a[],int b[],int len)
{//��ASCII��ð������
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				char ta; int tb;
				ta = a[j + 1];
				a[j + 1] = a[j];
				a[j] = ta;
				tb = b[j + 1];
				b[j + 1] = b[j];
				b[j] = tb;
			}
		}
}
void Select_min(HuffmanTree HT,int n,int &s1,int &s2)
{// ��HT[k](1��k��i-1����ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ�㣬������������HT�е����s1��s2
	int m1 = 10086, m2 = 10086;
	for(int i = 1; i <= n; i++)
	{
		if(HT[i].parent == 0 && m1 > HT[i].weight)
		{
			m2 = m1;
			m1 = HT[i].weight;
			s2 = s1;
			s1 = i;
			continue;
		}
		if(HT[i].parent == 0 && m2 > HT[i].weight)
		{
			m2 = HT[i].weight;
			s2 = i;
			continue;
		}
	}
}
int m;
void CreateHuffmanTree(HuffmanTree &HT,int n,int b[])
{//�����������HT
	if(n <= 1) return;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for(int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for(int i = 1; i <= n; i++)
	{		
		HT[i].weight = b[i - 1];
	}
	int s1 = 0, s2 = 0;
	for(int i = n + 1; i <= m; i++)
	{
		Select_min(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
	HC = new char*[n + 1];
	char* cd = new char[n];
	cd[n - 1] = '\0';
	for(int i = 1; i <= n; i++)
	{
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while(f != 0)
		{
			--start;
			if(HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}

void CharFrequency(char ch[],char a[],int b[],int &j)
{//ͳ�ƴ�Ƶ
	for(int i = 0; i < (int)strlen(ch); i++)
	{
		for(int k = 0; k <= 26; k++)
		{
			if(a[k] == ch[i]) 
			{
				b[k]++;
				break;
			}
			if(a[k] == '\0')
			{
				j++;
				a[k] = ch[i];
				b[k]++;
				break;
			}
		}
	}
}

void PrintHT(HuffmanTree HT)
{//������������Ĵ洢�ṹ����̬
	for(int i = 1; i <= m; i++)
		cout << i << " " << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
}
void PrintHC(HuffmanCode HC,char a[],int j)
{//���ÿ���ַ��Ĺ���������
	for(int i = 1; i <= j; i++)
	{
		if(i != 1)
			cout << " "; 
		cout << a[i - 1] << ":" << HC[i];
	}
	cout << endl;
}

int main()
{
	char ch[MAXSIZE];
	int i,j;
	while(cin>>ch)
	{
		if(ch[0]=='0') break;
		HuffmanTree HT;
		char a[MAXSIZE]={'\0'};
		int b[MAXSIZE]={0};
		j=0;      //jͳ�Ʋ�ͬ�ַ�������
		CharFrequency(ch,a,b,j);   //ͳ�ƴ�Ƶ
		Sort(a,b,j);     //��ASCII��ð������
		for(i=0;a[i]!='\0';i++)   //���ͳ�Ƴ������ַ��ͳ���Ƶ��
		{
			if(a[i+1]!='\0')
				cout<<a[i]<<":"<<b[i]<<" ";
			else
				cout<<a[i]<<":"<<b[i]<<endl;
		}
		//�����������
		CreateHuffmanTree(HT,i,b);    //�����������HT
		PrintHT(HT);      //������������Ĵ洢�ṹ����̬
		//����������
		HuffmanCode HC;    //�����HC
		CreateHuffmanCode(HT,HC,j);
		PrintHC(HC,a,j);    //���ÿ���ַ��Ĺ���������
		int k;
		for(i=0;ch[i]!='\0';i++)    //����������ַ���
		{
			for(k=0;k<j;k++)
			{
				if(ch[i]==a[k])
					cout<<HC[k+1];
			}
		}
		cout<<endl;
		cout<<ch<<endl;//����������ַ�������������ַ�����ͬ��
	}
	return 0;
}
