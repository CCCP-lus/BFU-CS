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
		
		//用优先队列实现排序 
		priority_queue<int, vector<int>, greater<int>>q;
		
		//出现字符频率统计 
		for(int i = 0; i < (int)str.length(); i++)
		{
			if(mpp.find(str[i]) == mpp.end())
				mpp[str[i]] = 1;
			else
				mpp[str[i]]++;
		}
		map<char, int>::iterator it;
		
		//存结果 
		for(it = mpp.begin(); it != mpp.end(); it++)
			q.push(it ->second);
		
		//计算哈夫曼编码 
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
