#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int max_height = 102;

int R, C, N, i, j, k, l;
char cave[101][101];
bool visited[101][101];
bool clusterCheck[101][101];
bool leftRight = true;	// 왼쪽 : true, 오른쪽 : false
vector<pair<int, int>> cluster;
//int fallMin[101];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void Input()
{
	cin >> R >> C;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			cin >> cave[i][j];
		}
	}
	cin >> N;
}

void CheckCave()
{
	// 초기화
	memset(visited, false, sizeof(visited));
	// 클러스터 파악
	// 공중에 떠있는지 여부 판별 -> 공중에 떠 있음 -> 추락
	queue<pair<int, int>> q;
	bool onAir;

	for (j = 0; j < R; j++)
	{
		onAir = false;
		for (k = 0; k < C; k++)
		{
			if (cave[j][k] == '.' || visited[j][k]) continue;

			cluster.clear();
			cluster.push_back({ j, k });

			q.push({ j, k });
			visited[j][k] = true;
			onAir = true; // 공중에 떠있는가?

			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;

				q.pop();

				for (l = 0; l < 4; l++)
				{
					int ny = y + dy[l];
					int nx = x + dx[l];

					if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || cave[ny][nx] == '.') continue;

					q.push({ ny, nx });
					cluster.push_back({ ny, nx });

					//fallMin[nx] = max(fallMin[nx], ny);
					visited[ny][nx] = true;
					if (ny == R - 1)	// 바닥에 닿아있으면
					{
						onAir = false;
					}
				}
			}

			if (onAir) // 공중에 떠 있으면 추락
			{
				memset(visited, false, sizeof(visited));
				memset(clusterCheck, false, sizeof(clusterCheck));

				for (j = 0; j < cluster.size(); j++)
				{
					int y = cluster[j].first;
					int x = cluster[j].second;
					clusterCheck[y][x] = true;
				}

				// 가장 낮은 높이 차 확인
				int fallheight = R - 1;

				for (j = 0; j < cluster.size(); j++)
				{
					int y = cluster[j].first;
					int x = cluster[j].second;
					// 땅(R-1)에서 미네랄 높이 만큼 빈 위치를 파악
					int ground = R - 1;
					for (k = R - 1; k > y; k--)
					{
						if (cave[k][x] == 'x' && !clusterCheck[k][x])
						{
							ground = k - 1;
						}
					}
					fallheight = min(fallheight, ground - y);
					//cout << "k = " <<k<< " {" << y << ", " << x << "} , " << fallheight << "\n";
				}
				// 가장 낮은 추락 높이를 파악했으면 추락한다.
				for (j = cluster.size() - 1; j >= 0; j--)
				{
					int curY = cluster[j].first;
					int curX = cluster[j].second;
					int nextY = curY + fallheight;

					if(!visited[curY][curX]) cave[curY][curX] = '.';
					cave[nextY][curX] = 'x';
					visited[nextY][curX] = true;
				}

				return;
			}
		}
	}
}

void Solve()
{
	int height, dheight;	// 막대기 던지는 높이와 파괴될 높이

	for (i = 0; i < N; i++)
	{
		// 파괴 되었는가?
		bool destroy = false;
		cin >> height;
		dheight = R - height;

		if (leftRight)	// 왼쪽 먼저 투척
		{
			for (j = 0; j < C; j++)
			{
				if (cave[dheight][j] == 'x')
				{
					//cout << dheight << ", " << j << "\n";
					cave[dheight][j] = '.';
					destroy = true;
					break;
				}
			}
			leftRight = false;
		}
		else // 오른쪽 먼저 투척
		{
			for (j = C - 1; j >= 0; j--)
			{
				if (cave[dheight][j] == 'x')
				{
					//cout << dheight << ", " << j << "\n";
					cave[dheight][j] = '.';
					destroy = true;
					break;
				}
			}
			leftRight = true;
		}

		// 파괴되지 않았으면 그대로
		if (!destroy) continue;
		CheckCave();
	}
		for (j = 0; j < R; j++)
		{
			for (k = 0; k < C; k++)
			{
				cout << cave[j][k];
			}
			cout << "\n";
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