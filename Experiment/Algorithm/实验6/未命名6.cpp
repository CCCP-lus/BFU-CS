#include<bits/stdc++.h>
using namespace std;

struct zuzhou 
{
	string name;
	string effect;
};

hash<string>ha;//哈希函数

const int N = 1e6 + 5;

zuzhou Name[N];//根据name找effect
zuzhou Effect[N];//根据effect找name

bool is_name[N];
bool is_effect[N];

int main()
{
	string str;
	while(cin >> str)
	{
		if (str == "END")
			break;
		
		//提取方括号内内容 
		string name = str.substr(str.find('[') + 1, str.find(']') - 1);
		int l = str.length() - name.length() - 3;
		//提取效果 
		string effect = str.substr(str.find(']') + 2, l);	
		
		unsigned long long hash_name = ha(name) % 177771;
		while (is_name[hash_name])//找不冲突的空间
		{
			hash_name = ((++hash_name) % 177771);
		}
		
		int hash_effect = ha(effect) % 177771;//effect的哈希值
		while (is_effect[hash_effect])
		{
			hash_effect = (++hash_effect) % 177771;
		}		
		
		Name[hash_name].name=name;
		Name[hash_name].effect = effect;
		Effect[hash_effect].name = name;
		Effect[hash_effect].effect = effect;
		is_name[hash_name] = true;
		is_effect[hash_effect] = true;
	}
	int n;
	cin >> n;
	getchar();
	
	while (n--)
	{
		string operation;
		getline(cin, operation);
		if (operation[0] == '[')
		{
			int ll = operation.length() - 2;
			operation = operation.substr(1, ll);
			int hash_name = ha(operation) % 177771;
			int last_hash = hash_name;//存最初的hash值，用来判断hash表全遍历
			bool flag=false;//判断是否找到
			do
			{
				if (!is_name[hash_name])//因为存的时候是紧邻向后找，查找的时候一旦发现空位就一定没有
				{
					break;
				}
				if (Name[hash_name].name == operation)
				{
					flag = true;
					break;
				}
				hash_name = (++hash_name) % 177771;
			} while (hash_name!=last_hash);
			if (flag)
			{
				cout << Name[hash_name].effect << endl;
			}
			else
			{
				cout << "silence" << endl;
			}
		}
		else
		{
			int hash_effect = ha(operation) % 177771;
			int last_hash = hash_effect;//存最初的哈希值，用来判断hash表全遍历
			bool flag=false;//判断是否找到
			do
			{
				if (!is_effect[hash_effect])//因为存的时候紧邻向后找，查找的时候一旦发现空位就肯定没有
					break;
				if (Effect[hash_effect].effect == operation)
				{
					flag = true;
					break;
				}
				hash_effect = (++hash_effect) % 177771;
			} while (hash_effect != last_hash);
			if (flag)
			{
				cout << Effect[hash_effect].name << endl;
			}
			else
			{
				cout << "silence" << endl;
			}
		}
	}	
	
	return 0;
}
