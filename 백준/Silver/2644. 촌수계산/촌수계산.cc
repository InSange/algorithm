#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, f1, f2, m;
bool visited[101];
vector<int> v[101];
int rel[101];
queue<int> q;

void Init()
{
	for (int i = 0; i < 100; i++)
	{
		rel[i] = 0;
		visited[i] = 0;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Init();

	cin >> n >> f1 >> f2 >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push(f1);
	visited[f1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (next == f2)
			{
				cout << rel[cur] + 1 << "\n";
				return 0;
			}
			if (visited[next]) continue;
			q.push(next);
			rel[next] = rel[cur] + 1;
			visited[next] = true;
		}
	}
	cout << -1 << "\n";

	return 0;
}