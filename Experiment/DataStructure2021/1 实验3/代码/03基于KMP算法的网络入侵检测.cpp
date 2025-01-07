#include "iostream"
#include "cstring"
#include<stdlib.h>
using namespace std;


#define MAXLEN 5000			//������󳤶�
typedef struct{   
   char *ch;			//�洢����һά����
   int length;				//���ĵ�ǰ����   
}HString;


void InputRule(HString ip[],int n)
{//����n�����򣬲������е�n��ip��ַ��ŵ�ip���� 
	for(int i = 0; i < n; i++)
		ip[i].ch = new char[100];
	for(int i = 0; i < n; i++)
	{
		string ss; int a, b;
		getline(cin, ss);
		for(int j = 0; j < (int)ss.length(); j++)
		{
			if(ss[j] == ':' && ss[j - 1] == 'p')
				a = j + 1;
			if(ss[j] == ' ' && ss[j + 1] == 'm')
				b = j - 1;
		}
		for(int j = a, k = 0; j <= b; j++, k++)
		{
			ip[i].ch[k] = ss[j];
			ip[i].length = b - a + 1;
		}
	}
}

void InputLog(HString &log,int m)
{//����m����־�����ϲ���ŵ�log������log��length
	delete log.ch;
	log.ch=(char *)malloc(sizeof(char)*10000);
	string s;
	for(int i = 0; i < m; i++)
	{
		string ss;
		getline(cin, ss);
		s += ss;
	}
	for(int i = 0; i < (int)s.length(); i++)
		log.ch[i] = s[i];
	log.length = (int)s.length();
}

void GetNext(HString pattern,int* next)
{//��ģʽ��pattern��next����ֵ����������next
	next[0] = -1;
	int k = -1;
	for(int q = 1; q <= pattern.length; q++)
	{
		while(k > -1 && pattern.ch[k + 1] != pattern.ch[q])
			k = next[k];
		if(pattern.ch[k + 1] == pattern.ch[q])
			k++;
		next[q] = k;
	}
}

int Index_KMP(HString target,HString pattern,int* next)
{//KMPƥ���㷨,targetΪ������patternΪ�Ӵ���
//ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
//����GetNext������ȡģʽ����next����
	GetNext(pattern, next);
	int k = -1, i = 0;
	for(i = 0; i < target.length; i++)
	{
		while(k > -1 && pattern.ch[k + 1] != target.ch[i])
			k = next[k];
		if(pattern.ch[k + 1] == target.ch[i])
			k++;
		if(k == pattern.length - 1)
			return i - pattern.length + 1;
	}
	return -1;
}

int main()
{
	int n,m;
    cin>>n>>m;
    getchar();
    

    HString ip[5000];//ip������n��ip��ַ 
    InputRule(ip,n);

    HString log;
	log.ch=(char *)malloc(sizeof(char)*5000);
    strcpy(log.ch,"");
    log.length=0;
    InputLog(log,m);
    
    for(int i=0;i<n;i++)
    {
    	int *next=new int[ip[i].length];
        if(Index_KMP(log,ip[i],next)!= -1)
        {
            cout<<"Intrusion."<<endl;
            return 0;
        }
    }
    cout<<"No Intrusion."<<endl;
    return 0;
    
}
