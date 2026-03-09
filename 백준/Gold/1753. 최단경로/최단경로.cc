#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int V, E, K, u, v, w;
vector<vector<pair<int, int>>> graph;
vector<int> visited;

void Input()
{
	cin >> V >> E;
	cin >> K;

	graph.assign(V + 1, vector<pii>());

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ w, v });
	}

	visited.assign(V + 1, 1e9);
}

void Solve()
{
	priority_queue < pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, K });
	visited[K] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;

		pq.pop();
		if (visited[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].second;
			int nextCost = cost + graph[cur][i].first;

			if (visited[next] > nextCost)
			{
				visited[next] = nextCost;
				pq.push({ nextCost, next });
			}
		}
	}

	for (int i = 1; i < V + 1; i++)
	{
		if (visited[i] == 1e9) cout << "INF" << "\n";
		else cout << visited[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}