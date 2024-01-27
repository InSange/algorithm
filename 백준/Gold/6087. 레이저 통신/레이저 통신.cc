#include <iostream>
#include <queue>

using namespace std;

int W, H, i, j;
char map[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int visited[101][101];

pair<pair<int, int>, pair<int, int>> start, last;
bool firstC = true;
queue<pair<pair<int, int>, pair<int, int>>> q; // y, x, direction, val

void Input()
{
	cin >> W >> H;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C')
			{
				if (firstC)
				{
					start.first.first = i;
					start.first.second = j;
					start.second.second = 0;
					firstC = false;
				}
				else
				{
					last.first.first = i;
					last.first.second = j;
					last.second.second = 99999999;
					visited[i][j] = 99999999;
				}
			}
			else visited[i][j] = 99999999;
		}
	}
}

void Solve()
{
	q.push({ {start.first.first, start.first.second}, { -1, start.second.second} });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int d = q.front().second.first;
		int store_val = q.front().second.second;
		q.pop();

		for (i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 맵 밖이거나 벽이면 스킵
			while (ny >= 0 && ny < H && nx >= 0 && nx < W)
			{
				if (map[ny][nx] == '*') break;
				if (visited[ny][nx] > store_val + 1)
				{
					visited[ny][nx] = store_val + 1;
					q.push({ { ny, nx }, { i, visited[ny][nx] } });
				}
				ny += dy[i];
				nx += dx[i];
			}
		}
	}

	cout << visited[last.first.first][last.first.second]-1<< "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}