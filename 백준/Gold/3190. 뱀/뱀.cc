#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
deque<pair<int, int>> snake;
queue<pair<int, char>> actions;
int N, K, L;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int curDir = 0;

void Input()
{
	cin >> N >> K;

	board.assign(N + 1, vector<int>(N + 1, 0));

	int r, c;
	for (int i = 0; i < K; i++)
	{
		cin >> r >> c;

		board[r][c] = 1;
	}

	cin >> L;

	int X;
	char C;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;

		actions.push({ X, C });
	}
}

int Solve()
{
	snake.push_front({ 1, 1 });
	board[1][1] = 2;

	int time = 0;

	int moveVal = actions.front().first;
	char turnDir = actions.front().second;
	actions.pop();

	while(true)
	{
		int nextY = snake.front().first + dy[curDir];
		int nextX = snake.front().second + dx[curDir];

		time++;
		if (nextY == 0 || nextX == 0 || nextY > N || nextX > N) return time;
		if (board[nextY][nextX] == 2) return time;

		// 사과가 없으면 꼬리 뺌, 있으면 그대로
		if (board[nextY][nextX] == 0)
		{
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		snake.push_front({ nextY, nextX });
		board[nextY][nextX] = 2;

		if (time == moveVal)
		{
			if (turnDir == 'L') curDir = (curDir + 3) % 4;
			else curDir = (curDir + 1) % 4;

			if(actions.empty()) continue;
			moveVal = actions.front().first;
			turnDir = actions.front().second;
			actions.pop();
		}
	}

	return time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	cout << Solve();

	return 0;
}