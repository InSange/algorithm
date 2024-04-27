#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> relation;
vector<int> answer;
vector<bool> visited;
queue<int> invite;


void Solve()
{
	cin >> n >> m;
	n++;
	relation.assign(n, vector<int>());
	visited.assign(n, false);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	invite.push(1);
	visited[1] = true;
	while (!invite.empty())
	{
		int cur = invite.front();
		invite.pop();

		for (auto num : relation[cur])
		{
			if (visited[num]) continue;
			if (cur == 1) invite.push(num);
			answer.push_back(num);
			visited[num] = true;
		}
	}

	cout << answer.size(); 
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}