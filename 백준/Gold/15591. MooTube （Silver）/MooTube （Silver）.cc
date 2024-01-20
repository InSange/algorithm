#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[5001];
queue<int> q;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, Q, pi, qi, r, ki, vi;

	cin >> N >> Q;
	
	for (int i = 1; i < N; i++)
	{
		cin >> pi >> qi >> r;
		v[pi].push_back({ qi, r });
		v[qi].push_back({ pi, r });
	}

	for (int i = 0; i < Q; i++)
	{
		cin >> ki >> vi;

		q.push(vi);

		bool visited[5001];
		memset(visited, false, sizeof(visited));
		visited[vi] = true;
		int answer = 0;

		while (!q.empty())
		{
			int index = q.front();
			q.pop();

			for (int j = 0; j < v[index].size(); j++)
			{
				int next_index = v[index][j].first;
				int next_USADO = v[index][j].second;

				if (!visited[next_index] && next_USADO >= ki)
				{
					q.push(next_index);
					visited[next_index] = true;
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}

	return 0;
}