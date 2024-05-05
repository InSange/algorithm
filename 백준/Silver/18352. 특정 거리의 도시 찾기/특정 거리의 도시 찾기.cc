#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K, X, a, b, minDist;
deque<deque<int>> town;
queue<int> q;
vector<int> dist;
vector<int> answer;

void Solve()
{
	cin >> N >> M >> K >> X;
	N++;
	town.assign(N, deque<int>());
	dist.assign(N, -1);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		town[a].push_back(b);
	}

	minDist = -1;
	q.push(X);
	dist[X] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (const int& val : town[cur])
		{
			if (dist[val] != -1) continue;
			q.push(val);
			dist[val] = dist[cur] + 1;
			minDist = max(minDist, dist[val]);
		}
	}

	for (int i = 0; i < dist.size(); i++)
	{
		if (dist[i] == K) answer.push_back(i);
	}

	if (answer.size())
	{
		for (const int& val : answer)
		{
			cout << val << "\n";
		}
	}
	else cout << -1;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}