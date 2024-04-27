#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int N, answer1, answer2;

vector<string> section;
vector<vector<bool>> visited1, visited2;	// 1 정상 2 색약인
queue<pair<int, int>> q1, q2; // nextY, nextX	1 정상 2 색약인

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool OutOfBounds(int ny, int nx)
{
	return (ny < 0 || N <= ny || nx < 0 || N <= nx);
}

void Solve()
{
	cin >> N;
	visited1.assign(N, vector<bool>(N, false));
	visited2.assign(N, vector<bool>(N, false));
	answer1 = 0, answer2 = 0;

	string line;
	for (int i = 0; i < N; i++)
	{
		cin >> line;
		section.push_back(line);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited1[i][j]) continue;
			answer1++;
			q1.push({ i, j });
			visited1[i][j] = true;

			char curColor;
			int y, x;
			while (!q1.empty())
			{
				y = q1.front().first;
				x = q1.front().second;
				q1.pop();
				curColor = section[y][x];

				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (OutOfBounds(ny, nx)) continue;
					if (visited1[ny][nx]) continue;
					if (curColor != section[ny][nx]) continue;

					q1.push({ ny, nx });
					visited1[ny][nx] = true;
				}
			}

			if (visited2[i][j]) continue;
			answer2++;
			q2.push({ i, j });
			visited2[i][j] = true;

			while (!q2.empty())
			{
				y = q2.front().first;
				x = q2.front().second;

				q2.pop();
				curColor = section[y][x];

				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (OutOfBounds(ny, nx)) continue;
					if (visited2[ny][nx]) continue;
					if (curColor == 'B' && curColor != section[ny][nx]) continue;
					if (curColor != 'B' && section[ny][nx] == 'B') continue;
					q2.push({ ny, nx });
					visited2[ny][nx] = true;
				}
			}
		}
	}

	cout << answer1 << " " << answer2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}