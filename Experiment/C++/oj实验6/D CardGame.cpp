#include<bits/stdc++.h>
using namespace std;

void play(std::queue<int>& q)
{
	cout << q.front() << " ";
	q.pop();
	q.push(q.front());
	q.pop();
}

int main()
{
	std::queue<int> card;
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		card.push(i+1);
	while(card.size() > 1)
		play(card);
	cout << card.front() << endl;
	return 0;
}
