#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_INT = 99999999;
int N, M, X, n, m, t, answer;
vector<vector<pair<int, int>>> towns;
vector<int> dist;
int result, temp;

void dijkstra(int start, int end)
{
	dist.clear();
	dist.resize(N + 1, MAX_INT);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cur == end)
		{
			temp = dist[cur];
			break;
		}
		for (auto road : towns[cur])
		{
			int next = road.first;
			int next_cost = road.second + cost;

			if (next_cost < dist[next])
			{
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
}

void Solve()
{
	cin >> N >> M >> X;

	answer = 0;
	towns.assign(N + 1, vector<pair<int ,int>>());

	while (M--)
	{
		cin >> n >> m >> t;
		towns[n].push_back({ m, t });
	}

	for (int i = 1; i <= N; i++)
	{
		result = 0;
		dijkstra(i, X);
		result += temp;
		dijkstra(X, i);
		result += temp;
		answer = max(answer, result);
	}

	cout << answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}