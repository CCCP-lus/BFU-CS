#include<iostream>
#include<cstring>
using namespace std;
void Count(string c,int b[])
{//ͳ���ַ����ֵ�Ƶ��
	for(int i = 0; i < (int)c.length(); i++)
	{
		if(isdigit(c[i]))
		{
			b[(int)c[i] - 48]++;
		}
		else
		{
			b[(int)c[i] - 65 + 10]++;
		}
	}
	for(int i = 0; i < 36; i++)
	{
		if(b[i])
		{
			if(i < 10)
				cout << i << ":" << b[i] << endl;
			if(i >= 10)
			{
				char c = (char)(i + 65 - 10);
				cout << c << ":" << b[i] << endl;
			}
		}
	}
}

int main()
{
    string c;     //�洢������ַ���
    while(cin>>c)
    {
        if(c=="0") break;
        int *b=new int[36]{0};        	//�洢��Ӧ�ַ��ĸ���
        Count(c,b);
    }
    return 0;
}
