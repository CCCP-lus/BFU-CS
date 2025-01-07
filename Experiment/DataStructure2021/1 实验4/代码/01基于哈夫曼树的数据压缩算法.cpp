#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef struct
{//哈夫曼树结点的形式
	int weight;               //结点的权值
	int parent,lchild,rchild;  //结点的双亲、左孩子、右孩子的下标
}HTNode,*HuffmanTree;       //动态分配数组存储哈夫曼树
typedef char **HuffmanCode;   //定义编码表类型
int Search(char a[],char ch)
{//查找数组中字符ch所在的位置，返回数组下标，否则返回-1
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
{//按ASCII码冒泡排序
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
{// 在HT[k](1≤k≤i-1）中选择两个其双亲域为0且权值最小的结点，并返回它们在HT中的序号s1和s2
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
{//构造哈夫曼树HT
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
{//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
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
{//统计词频
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
{//输出哈夫曼树的存储结构的终态
	for(int i = 1; i <= m; i++)
		cout << i << " " << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
}
void PrintHC(HuffmanCode HC,char a[],int j)
{//输出每个字符的哈夫曼编码
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
		j=0;      //j统计不同字符的数量
		CharFrequency(ch,a,b,j);   //统计词频
		Sort(a,b,j);     //按ASCII码冒泡排序
		for(i=0;a[i]!='\0';i++)   //输出统计出来的字符和出现频率
		{
			if(a[i+1]!='\0')
				cout<<a[i]<<":"<<b[i]<<" ";
			else
				cout<<a[i]<<":"<<b[i]<<endl;
		}
		//构造哈夫曼树
		CreateHuffmanTree(HT,i,b);    //构造哈夫曼树HT
		PrintHT(HT);      //输出哈夫曼树的存储结构的终态
		//哈夫曼编码
		HuffmanCode HC;    //编码表HC
		CreateHuffmanCode(HT,HC,j);
		PrintHC(HC,a,j);    //输出每个字符的哈夫曼编码
		int k;
		for(i=0;ch[i]!='\0';i++)    //输出编码后的字符串
		{
			for(k=0;k<j;k++)
			{
				if(ch[i]==a[k])
					cout<<HC[k+1];
			}
		}
		cout<<endl;
		cout<<ch<<endl;//输出解码后的字符串（与输入的字符串相同）
	}
	return 0;
}
