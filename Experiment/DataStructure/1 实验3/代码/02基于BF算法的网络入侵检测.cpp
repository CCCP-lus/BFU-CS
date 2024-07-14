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
{//����m����־�����ϲ���ŵ�log
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

int Index_BF(HString S, HString T)
{//��ģʽƥ���㷨,SΪ����(Ŀ�괮)��TΪ�Ӵ�(ģʽ��)��
//ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
	int i = 0, j = 0;
	while(i < S.length && j < T.length)
	{
		if(S.ch[i] == T.ch[j])
		{
			i++;
			j++;   	
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
   	}
   	if(j >= T.length) 
		return i - T.length;
   	else return -1;
}

int main()
{
	int n,m;
    cin>>n>>m;
    getchar();
    

    HString ip[5000];//ip������n��ip��ַ 
    InputRule(ip,n);

    HString log;
	 log.ch=(char *)malloc(sizeof(char)*5000);	//���￪С�� 
    strcpy(log.ch,"");
    log.length=0;
    InputLog(log,m);
    
    for(int i=0;i<n;i++)
    {
        if(Index_BF(log,ip[i])!= -1)
        {
            cout<<"Intrusion."<<endl;
            return 0;
        }
    }
    cout<<"No Intrusion."<<endl;
    return 0;
    
}
