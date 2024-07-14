#include<iostream>
#include<string>
#include "cstring"
using namespace std;

#define ASCII_SIZE 256     //ASCII码共256位，可表示所有字符，作为坏字符数组的大小
#define MAXLEN 5000			//串的最大长度
typedef struct{   
   char *ch;				   //存储串的一维数组
   int length;				   //串的当前长度   
}HString;

void InputRule(HString ip[],int n)
{//将输入的n个ip地址存放到ip数组
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
{//将输入的m条日志合并存放到log，返回log的总长度
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

void getBC(HString pattern,int *bc)
{//得到坏字符bc数组
	for (int i = 0; i < ASCII_SIZE; i++)
	{
		bc[i] = -1;
	}

	for (int i = 0; i < pattern.length; i++)
	{
		bc[(int)pattern.ch[i]] = i;
	}
}

void getGS(HString pattern,int *suffix,bool *prefix)
{//得到好后缀gs，其中suffix为int类型数组存储后缀字符对应前面的位置，prefix为bool类型数组存储是否存在匹配的前缀字符串
//suffix和prefix共同构成好后缀数组
//	suffix = new int[MAXLEN];
//	prefix = new bool[MAXLEN];
	int n = pattern.length;
	for (int i = 0; i < n - 1; i++)
	{
		suffix[i] = -1;
		prefix[i] = false;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int j = i;
		int k = 0;
		while (j >= 0 && pattern.ch[j] == pattern.ch[n - 1 - k])
		{
			j--;
			k++;
			suffix[k] = j + 1;
		}
		if (j == -1)
			prefix[k] = true;
	}
}

int getGSMove(int *suffix,bool *prefix,int bc_pos,int pattern_length)
{//利用suffix和prefix数组，返回好后缀移动的次数
//bc_pos表示坏字符BC的位置（后一位为好后缀起点位置）
	int len = pattern_length - bc_pos - 1;
	if (suffix[len] != -1)
	{
		return bc_pos + 1 - suffix[len];
	}

	for (int i = bc_pos + 2; i < pattern_length; i++)
	{
		if (prefix[pattern_length - i])
			return i;
	}
	return 0;
}

int Index_BM(HString str,HString pattern)
{//在str.ch中匹配pattern.ch，匹配成功返回主串中所含子串第一次出现的位置，否则返回-1。
//分别求坏字符数组bc和好字符数组suffix、prefix，分别计算两个策略的移动位数，取大值作为最终移动位数
	int n = str.length;
	int m = pattern.length;
	int bc[ASCII_SIZE];
	int* suffix = new int[m];
	bool* prefix = new bool[m];

	getBC(pattern, bc);
	getGS(pattern, suffix, prefix);

	int i = 0;
	while (i <= n - m)
	{
		int j = 0;
		for (j = m - 1; j >= 0; j--)
		{
			if (pattern.ch[j] != str.ch[i + j])
				break;
		}
		if (j < 0)
		{
			delete suffix;
			delete prefix;
			return i;
		}
		else     
		{
			int numBc = j - bc[(int)str.ch[i + j]];
			int numGs = 0;
			if (j < m - 1)
			{
				numGs = getGSMove(suffix, prefix, m, j);
			}
			i += numBc > numGs ? numBc : numGs;
		}
	}
	delete suffix;
	delete prefix;
	return -1;
}

int main()
{
	 int n,m;
    cin>>n>>m;
    getchar();
    HString ip[5000];	//ip数组存放n个ip地址 
    InputRule(ip,n);	   //输入n行规则，从规则中找到所有的ip地址，保存至ip数组中

    HString log;
	 log.ch=(char *)malloc(sizeof(char)*5000);
    strcpy(log.ch,"");	//将log.ch初始化为空字符串
    log.length=0;
    InputLog(log,m);	//输入m行日志，将m行日志合并为1个长日志并保存至log中，返回长日志log的长度
    
    for(int i=0;i<n;i++)
    {
        if(Index_BM(log,ip[i])!=-1)		//返回值不为-1则匹配成功
        {
            cout<<"Intrusion."<<endl;
            return 0;
        }
    }
    cout<<"No Intrusion."<<endl;
    return 0;

}
