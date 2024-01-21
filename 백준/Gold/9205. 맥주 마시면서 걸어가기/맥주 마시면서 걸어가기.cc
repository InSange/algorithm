#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, goalY, goalX;
vector<pair<int, int>> v;
bool visited[102];
bool flag = false;

void Init()
{
	cin >> t;
}

void Input()
{
	cin >> n;
	n += 2;

	int y, x;

	for (int i = 0; i < n; i++)
	{
		cin >> y >> x;
		v.push_back({ y, x });
		if (i == n - 1)
		{
			goalY = y;
			goalX = x;
		}
	}
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ v[0] });
	visited[0] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 1; i < v.size(); i++)
		{
			if (visited[i]) continue;
			int ny = v[i].first;
			int nx = v[i].second;

			int cal = abs(ny - y) + abs(nx - x);
			if (cal > 1000) continue;
			if (ny == goalY && nx == goalX)
			{
				flag = true;
				return;
			}
			q.push({ ny, nx });
			visited[i] = true;
		}
	}
}

void Solve()
{
	for (int i = 0; i < t; i++)
	{
		v.clear();
		Input();

		memset(visited, false, sizeof(visited));
		flag = false;

		visited[0] = true;
		BFS();

		if (flag) cout << "happy" << "\n";
		else cout << "sad" << "\n";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Init();
	Solve();

	return 0;
}