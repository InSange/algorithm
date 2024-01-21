#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, i, j, k;
int arr[301][301];
bool visited[301][301];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void Input()
{
	cin >> N >> M;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = false;
		}
	}
}

void Solve()
{
	bool all_zero;
	int year = 0;
	int partition;

	while (true)
	{
		all_zero = true;
		partition = 0;
		memset(visited, false, sizeof(visited));

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (visited[i][j]) continue;
				if (arr[i][j] == 0) continue;
				if (all_zero) all_zero = false;

				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;

					q.pop();

					for (k = 0; k < 4; k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (visited[ny][nx]) continue;
						if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

						if (arr[ny][nx] == 0) arr[y][x]--;
						else
						{
							q.push({ ny, nx });
							visited[ny][nx] = true;
						}

						if (arr[y][x] < 0) arr[y][x] = 0;
					}
				}
				partition++;
			}
			if (partition > 1) break;
		}
		
		if (all_zero)
		{
			cout << 0 << "\n";
			return;
		}
		if (partition > 1)
		{
			cout << year << "\n";
			return;
		}
		year++;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}