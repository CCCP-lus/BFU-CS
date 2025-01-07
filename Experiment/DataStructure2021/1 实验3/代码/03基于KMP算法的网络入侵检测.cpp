#include "iostream"
#include "cstring"
#include<stdlib.h>
using namespace std;


#define MAXLEN 5000			//串的最大长度
typedef struct{   
   char *ch;			//存储串的一维数组
   int length;				//串的当前长度   
}HString;


void InputRule(HString ip[],int n)
{//输入n条规则，并将其中的n个ip地址存放到ip数组 
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
{//输入m条日志，并合并存放到log，返回log的length
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
{//求模式串pattern的next函数值并存入数组next
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
{//KMP匹配算法,target为主串，pattern为子串。
//匹配成功返回主串中所含子串第一次出现的位置，否则返回-1。
//调用GetNext函数获取模式串的next数组
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
    

    HString ip[5000];//ip数组存放n个ip地址 
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
