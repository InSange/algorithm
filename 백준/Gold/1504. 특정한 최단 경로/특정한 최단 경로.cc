#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int index;
	int distance;

	Node(int index, int distance)
	{
		this->index = index;
		this->distance = distance;
	}
};

vector<vector<Node>> nodes;
vector<vector<int>> distances;	// start from 1, v1, v2
int N, E, v1, v2;

void Find(int start, int order)
{
	vector<bool> visited(N + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push({ 0, start });
	visited[start] = true;
	distances[order][start] = 0;

	while (!q.empty())
	{
		int cur = q.top().second;
		int cur_dist = q.top().first;
		q.pop();


		for (auto val : nodes[cur])
		{
			int nextIndex = val.index;
			int dist = val.distance;

			if (distances[order][nextIndex] > dist + distances[order][cur])
			{
				distances[order][nextIndex] = dist + distances[order][cur];
				q.push({ dist, nextIndex });
			}
		}
	}
}

void Solve()
{
	cin >> N >> E;
	distances.assign(3, vector<int>(N + 1, 1e8));
	nodes.assign(N + 1, vector<Node>());

	while (E--)
	{
		int n1, n2, n3;

		cin >> n1 >> n2 >> n3;

		nodes[n1].push_back(Node(n2, n3));
		nodes[n2].push_back(Node(n1, n3));
	}

	cin >> v1 >> v2;
	Find(1, 0);
	Find(v1, 1);
	Find(v2, 2);

	int ans = min(distances[0][v1] + distances[1][v2] + distances[2][N], distances[0][v2] + distances[2][v1] + distances[1][N]);

	if (ans > 1e8-1) cout << -1;
	else cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}