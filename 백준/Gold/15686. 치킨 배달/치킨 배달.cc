#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<bool> visited;

int N, M, r, answer;

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> r;

			if (r == 0) continue;
			else if (r == 1) houses.push_back({ i + 1, j + 1 });
			else if (r == 2) chickens.push_back({ i + 1, j + 1 });
		}
	}

	visited.assign(chickens.size(), false);
	answer = 1e9;
}

void DFS(int start, int cnt)
{
	if (cnt < M)
	{
		for (int i = start; i < chickens.size(); i++)
		{
			visited[i] = true;
			DFS(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < houses.size(); i++)
		{
			int hY = houses[i].first, hX = houses[i].second;
			int dist = 1e9;

			for (int j = 0; j < chickens.size(); j++)
			{
				if (!visited[j]) continue;
				int cY = chickens[j].first, cX = chickens[j].second;

				dist = min(dist, abs(hY - cY) + abs(hX - cX));
			}

			sum += dist;
		}

		answer = min(answer, sum);
	}
}

void Solve()
{
	DFS(0, 0);

	cout << answer << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}