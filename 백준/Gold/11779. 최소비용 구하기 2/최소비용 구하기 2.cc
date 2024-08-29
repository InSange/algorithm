#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int index;
	int dist;

	Node(int index, int dist)
	{
		this->index = index;
		this->dist = dist;
	}
};

int n, m, start, goal;
vector<vector<Node>> nodes;
vector<int> paths;
vector<int> distances;
vector<bool> visited;

void Solve()
{
	cin >> n;

	nodes.assign(n + 1, vector<Node>());
	paths.assign(n + 1, 0);
	distances.assign(n + 1, 1e8);
	visited.assign(n + 1, false);

	cin >> m;

	while (m--)
	{
		int v1, v2, edge;

		cin >> v1 >> v2 >> edge;

		nodes[v1].push_back(Node(v2, edge));
	}
	
	cin >> start >> goal;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	distances[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cur_index = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();

		if (cur_dist > distances[cur_index]) continue;
		for (auto node : nodes[cur_index])
		{
			int next_index = node.index;
			int next_dist = node.dist + cur_dist;

			if (next_dist < distances[next_index])
			{
				distances[next_index] = next_dist;
				pq.push({ next_dist, next_index });
				paths[next_index] = cur_index;
			}
		}
	}

	cout << distances[goal] << "\n";
	
	vector<int> ans;

	ans.push_back(goal);
	while (goal != start)
	{
		ans.push_back(paths[goal]);
		goal = paths[goal];
	}

	cout << ans.size() << "\n";

	auto printReverse = [&ans]() {
		for (auto it = ans.rbegin(); it != ans.rend(); ++it)
		{
			cout << *it << " ";
		}
		};

	printReverse();
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}