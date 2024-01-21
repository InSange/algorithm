#include <iostream>
#include <stack>

using namespace std;
// 북, 동, 남, 서 -> 반 시계 방향으로 이동해야함, 역순
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int room[51][51];
bool roomClear[51][51];
int N, M, r, c, d, i, j, k, cnt;

void Init()
{
	for (i = 0; i < 51; i++)
	{
		for (j = 0; j < 51; j++)
		{
			room[i][j] = 0;
			roomClear[i][j] = false;
		}
	}

	cnt = 0;
}

void Input()
{	// ROOM SIZE
	cin >> N >> M;
	// CLEANER LOCATION, DIRECTION
	cin >> r >> c >> d;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> room[i][j];
		}
	}
}

void Solve()
{
	stack<pair<int, int>> st;

	st.push({ r, c });

	while (!st.empty())
	{
		int y = st.top().first;
		int x = st.top().second;
		st.pop();

		// 1번 조건
		if (!roomClear[y][x])
		{
			cnt++;
			roomClear[y][x] = true;
			room[y][x] = 2;
		}
		// 4칸 청소 여부 확인
		bool allClear = true;
		for (k = 0; k < 4; k++)
		{
			int direction = (d + 3 - k) % 4; // reverse
			int ny = y + dy[direction];
			int nx = x + dx[direction];

			if (ny < 0 || ny > N || nx < 0 || nx > M) continue;
			if (room[ny][nx] == 1 || roomClear[ny][nx] == true) continue;
			// 4칸중 청소 안된 곳 발견
			allClear = false;
			d = direction;
			st.push({ ny, nx });
			break;
		}
		// 4칸 청소 다 되어있음
		if (allClear)
		{	// 방향을 유지한채로 뒤로
			int ny = y - dy[d];
			int nx = x - dx[d];

			if (room[ny][nx] == 1)
			{
				cout << cnt << "\n";
				return;
			}
			st.push({ ny, nx });
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Init();
	Input();
	Solve();

	return 0;
}