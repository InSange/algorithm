#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K, X, A, B;
int cur, dist;
queue<pair<int, int>> q;
vector<vector<int>> towns;
vector<bool> visited;
priority_queue<int, vector<int>, greater<int>> answer;

void Solve()
{
	cin >> N >> M >> K >> X;

	N++;
	towns.assign(N, vector<int>());
	visited.assign(N, false);

	while (M--)
	{
		cin >> A >> B;
		towns[A].push_back(B);
	}

	q.push({ X, 0 });
	visited[X] = true;

	while (!q.empty())
	{
		cur = q.front().first;
		dist = q.front().second;

		q.pop();

		if (dist == K)
		{
			answer.push(cur);
			continue;
		}

		for (auto v : towns[cur])
		{
			if (visited[v]) continue;
			q.push({ v, dist + 1 });
			visited[v] = true;
		}
	}

	if (answer.empty())
	{
		cout << -1;
		return;
	}

	while (!answer.empty())
	{
		cout << answer.top() << "\n";
		answer.pop();
	}
	return;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}