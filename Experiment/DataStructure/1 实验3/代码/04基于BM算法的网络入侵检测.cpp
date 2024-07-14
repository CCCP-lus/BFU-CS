#include<iostream>
#include<string>
#include "cstring"
using namespace std;

#define ASCII_SIZE 256     //ASCII�빲256λ���ɱ�ʾ�����ַ�����Ϊ���ַ�����Ĵ�С
#define MAXLEN 5000			//������󳤶�
typedef struct{   
   char *ch;				   //�洢����һά����
   int length;				   //���ĵ�ǰ����   
}HString;

void InputRule(HString ip[],int n)
{//�������n��ip��ַ��ŵ�ip����
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
{//�������m����־�ϲ���ŵ�log������log���ܳ���
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
{//�õ����ַ�bc����
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
{//�õ��ú�׺gs������suffixΪint��������洢��׺�ַ���Ӧǰ���λ�ã�prefixΪbool��������洢�Ƿ����ƥ���ǰ׺�ַ���
//suffix��prefix��ͬ���ɺú�׺����
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
{//����suffix��prefix���飬���غú�׺�ƶ��Ĵ���
//bc_pos��ʾ���ַ�BC��λ�ã���һλΪ�ú�׺���λ�ã�
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
{//��str.ch��ƥ��pattern.ch��ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
//�ֱ����ַ�����bc�ͺ��ַ�����suffix��prefix���ֱ�����������Ե��ƶ�λ����ȡ��ֵ��Ϊ�����ƶ�λ��
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
    HString ip[5000];	//ip������n��ip��ַ 
    InputRule(ip,n);	   //����n�й��򣬴ӹ������ҵ����е�ip��ַ��������ip������

    HString log;
	 log.ch=(char *)malloc(sizeof(char)*5000);
    strcpy(log.ch,"");	//��log.ch��ʼ��Ϊ���ַ���
    log.length=0;
    InputLog(log,m);	//����m����־����m����־�ϲ�Ϊ1������־��������log�У����س���־log�ĳ���
    
    for(int i=0;i<n;i++)
    {
        if(Index_BM(log,ip[i])!=-1)		//����ֵ��Ϊ-1��ƥ��ɹ�
        {
            cout<<"Intrusion."<<endl;
            return 0;
        }
    }
    cout<<"No Intrusion."<<endl;
    return 0;

}
