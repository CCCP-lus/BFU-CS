#include<bits/stdc++.h>
using namespace std;

const int maxn = 400100;	//字典树最大节点数
const int ssize = 26;

struct Trie
{
	int ch[maxn][ssize];	//ch[i][j] == k表示i结点的第j个儿子是k 
	int val[maxn];			//val[i] == x表示i结点权值x 
	int sz;					//字典树一共有sz个节点,从0到sz-1标号
}; 

Trie trie;
void insert(string s)
{
	int u = 0;
	for(int i = 0; i < (int)s.length(); i++)
	{
		int x = s[i] - 'a';
		if(trie.ch[u][x] == 0)
		{
			trie.ch[u][x] = trie.sz++;
		}
		u = trie.ch[u][x];
		trie.val[u]++;
		
	}
}

bool find(string s)
{
	int u = 0;
	for(int i = 0; i < (int)s.length(); i++)
	{
		int x = s[i] - 'a';
		if(trie.ch[u][x] == 0)
			return false;
		u = trie.ch[u][x];
	}
	
	if(trie.val[u] != 0)
		return true;
	return false;
}

int main()
{
	string s;
	trie.sz = 1;
    memset(trie.ch, 0, sizeof(trie.ch));//ch值为0表示没有儿子
    memset(trie.val, 0, sizeof(trie.val));
    while (getline(cin,s))
    {
        if (s.empty()) 
            break;
        insert(s);
    }
    while (getline(cin,s))
    {
        if (s.empty()) 
            break;
        if (find(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
	return 0;
}
