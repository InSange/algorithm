#include <iostream>
#include <vector>

using namespace std;

struct info
{
	int y;
	int x;
	int direction;
};

// 우, 좌, 위, 아래
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

int pan[13][13] = {};
info horses[11];
vector<int> horse_arr[13][13];
int N, K, c, r, d, turn = 0;
bool flag = false; // 4개 이상시 탈출

void Input()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> pan[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> c >> r >> d;

		c--;
		r--;
		horses[i].y = c;
		horses[i].x = r;
		horses[i].direction = d-1;

		horse_arr[c][r].push_back(i);
	}
}

void Solve()
{
	while (turn < 1001)
	{
		turn++;

		for (int i = 0; i < K; i++)
		{
			info* horse = &horses[i];

			int y = horse->y;
			int x = horse->x;
			int dir = horse->direction;

			if (horse_arr[y][x][0] == i)
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				// 체스판 범위를 벗어날 경우와 파란색 판일 경우
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || pan[ny][nx] == 2)
				{
					if (dir == 0) dir = 1;
					else if (dir == 1) dir = 0;
					else if (dir == 2) dir = 3;
					else dir = 2;

					ny = y + dy[dir];
					nx = x + dx[dir];
					horse->direction = dir;
				}
				// 또 범위를 벗어나거나 파란색일 경우
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || pan[ny][nx] == 2) continue;
				if (pan[ny][nx] == 0) // 흰색일 경우
				{
					for (int j = 0; j < horse_arr[y][x].size(); j++)
					{
						int index = horse_arr[y][x][j];
						horse_arr[ny][nx].push_back(index);

						horses[index].y = ny;
						horses[index].x = nx;
					}

					horse_arr[y][x].clear();
				}
				else if (pan[ny][nx] == 1) // 빨간색일 경우
				{
					for (int j = horse_arr[y][x].size()-1; j >= 0; j--)
					{
						int index = horse_arr[y][x][j];
						horse_arr[ny][nx].push_back(index);

						horses[index].y = ny;
						horses[index].x = nx;
					}

					horse_arr[y][x].clear();
				}

				if (horse_arr[ny][nx].size() >= 4)
				{
					flag = true;
					return;
				}
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	if (flag) cout << turn << "\n";
	else cout << -1 << "\n";

	return 0;
}