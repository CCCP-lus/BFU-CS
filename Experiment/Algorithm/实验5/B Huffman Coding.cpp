#include<bits/stdc++.h>
using namespace std;

map<char, int> mpp;

int main()
{
	int times; cin >> times;	
	while(times--)
	{
		mpp.clear();
		int m; cin >> m;
		string str; cin >> str;
		
		//�����ȶ���ʵ������ 
		priority_queue<int, vector<int>, greater<int>>q;
		
		//�����ַ�Ƶ��ͳ�� 
		for(int i = 0; i < (int)str.length(); i++)
		{
			if(mpp.find(str[i]) == mpp.end())
				mpp[str[i]] = 1;
			else
				mpp[str[i]]++;
		}
		map<char, int>::iterator it;
		
		//���� 
		for(it = mpp.begin(); it != mpp.end(); it++)
			q.push(it ->second);
		
		//������������� 
		int cnt = 0;
		while(q.size() >= 2)
		{
			int a, b;
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			cnt += a + b;
			q.push(a + b);
		} 
//		cout << cnt << endl;
		if(cnt <= m)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
