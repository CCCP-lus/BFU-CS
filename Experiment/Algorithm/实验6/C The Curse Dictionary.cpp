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
	while (getline(cin,str))
	{
		if (str == "END")
			break;
		
		//提取方括号内内容
		string name = str.substr(str.find('[') + 1, str.find(']') - 1);
		int l = str.length() - name.length() - 3;
		
		//提取效果
		string effect = str.substr(str.find(']') + 2, l);
		
		int hash_name = ha(name) % 177771;
		//放置在合适位置 
		while (is_name[hash_name])
		{
			hash_name = (++hash_name) % 177771;
		}
		
		int hash_effect = ha(effect) % 177771;
		//放置在合适位置 
		while (is_effect[hash_effect])
		{
			hash_effect = (++hash_effect) % 177771;
		}
		
		//相应存储 
		Name[hash_name].name=name;
		Name[hash_name].effect = effect;
		Effect[hash_effect].name = name;
		Effect[hash_effect].effect = effect;
		is_name[hash_name] = true;
		is_effect[hash_effect] = true;
	}
	int n;
	cin >> n;
	getchar();	//有个回车 
	
	while (n--)
	{
		string operation;
		getline(cin, operation);
		//name 
		if (operation[0] == '[')
		{
			int ll = operation.length() - 2;
			operation = operation.substr(1, ll);
			int hash_name = ha(operation) % 177771;
			
			//存最初的hash值，用来判断hash表全遍历
			int last_hash = hash_name;
			
			bool flag=false;
			do
			{
				//紧邻向后找，一旦发现空位就一定没有
				if (!is_name[hash_name])
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
		//effect
		else
		{
			int hash_effect = ha(operation) % 177771;
			
			//存最初的hash值，用来判断hash表全遍历
			int last_hash = hash_effect;
			bool flag=false;
			do
			{
				//紧邻向后找，一旦发现空位就一定没有
				if (!is_effect[hash_effect])
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
