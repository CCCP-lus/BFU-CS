#include<iostream>
#define MAXSIZE 100
using namespace std;
void Insert(char s[],char t[],int pos,int LenS,int LenT)
{//�ַ����Ĳ���
	for(int i = LenS - 1 + LenT; i >= pos - 1 + LenT; i--)
		s[i] = s[i - LenT];
	for(int i = pos - 1, j = 0; j < LenT; i++, j++)
		s[i] = t[j];
	s[LenS + LenT] = '\0';
	cout << s << endl;
}

int main()
{
    int pos;
    while(cin>>pos)    	              //�������λ��pos
    {
        if(pos<=0) break;
        char s[MAXSIZE],t[MAXSIZE];
        cin>>s>>t;            	     //�����ַ���s��t
        int LenS=0,LenT=0;
        while(s[LenS]!='\0') LenS++;  //���ַ���s�ĳ���LenS
        while(t[LenT]!='\0') LenT++;  //���ַ���t�ĳ���LenT
        if(pos>LenS) break;           //����λ�÷Ƿ�
        Insert(s,t,pos,LenS,LenT);
    }
    return 0;
}
