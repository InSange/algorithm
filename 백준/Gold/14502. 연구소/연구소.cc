#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, ans;

vector<vector<int>> vMap;
vector<pair<int, int>> emptySpaces;

int d[5] = { 0, 1, 0, -1, 0 };

void Input()
{
	cin >> N >> M;

	vMap.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> vMap[i][j];
			if (vMap[i][j] == 0) emptySpaces.push_back({ i, j });
		}
	}
}

bool OutBounds(int y, int x)
{
	return y < 0 || x < 0 || y >= N || x >= M;
}

void BFS()
{
	queue<pii> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vMap[i][j] == 2) q.push({ i, j });
		}
	}

	vector<vector<int>> temp(vMap);

	while (!q.empty())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nY = y + d[i], nX = x + d[i + 1];

			if (OutBounds(nY, nX)) continue;
			if (temp[nY][nX] != 0) continue;
			temp[nY][nX] = 2;
			q.push({ nY, nX });
		}
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 0) sum++;
		}
	}

	ans = max(ans, sum);
}

void Solve()
{
	ans = 0;
	Input();

	for (int i = 0; i < emptySpaces.size() - 2; i++)
	{
		for (int j = i + 1; j < emptySpaces.size() - 1; j++)
		{
			for (int k = j + 1; k < emptySpaces.size(); k++)
			{
				vMap[emptySpaces[i].first][emptySpaces[i].second] = 1;
				vMap[emptySpaces[j].first][emptySpaces[j].second] = 1;
				vMap[emptySpaces[k].first][emptySpaces[k].second] = 1;

				BFS();

				vMap[emptySpaces[i].first][emptySpaces[i].second] = 0;
				vMap[emptySpaces[j].first][emptySpaces[j].second] = 0;
				vMap[emptySpaces[k].first][emptySpaces[k].second] = 0;
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	cout << ans << "\n";

	return 0;
}