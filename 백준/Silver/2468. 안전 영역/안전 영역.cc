#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, i, j, k, maxheight;
int arr[101][101];
bool visited[101][101];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void Init()
{
	maxheight = 0;

	for (i = 0; i < 101; i++)
	{
		for (j = 0; j < 101; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void Input()
{
	cin >> N;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			maxheight = max(maxheight, arr[i][j]);
		}
	}
}

void Solve()
{
	int answer = 0;
	
	for (int d = 0; d <= maxheight; d++)
	{
		int cnt = 0;
		memset(visited, false, sizeof(visited));

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (visited[i][j] || arr[i][j] <= d) continue;

				q.push({ i, j });

				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (k = 0; k < 4; k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (ny >= 0 && ny < N && nx >= 0 && nx < N
							&& visited[ny][nx] == false && arr[ny][nx] > d)
						{
							q.push({ ny, nx });
							visited[ny][nx] = true;
						}
					}
				}
				cnt++;
			}
		}

		answer = max(cnt, answer);
	}

	cout << answer << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Init();
	Input();
	Solve();

	return 0;
}