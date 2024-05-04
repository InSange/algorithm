#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, l, s, t;
pair<int, int> start, target;

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

queue<pair<pair<int, int>, int>> q; // first는 현재 좌표, second는 횟수
vector<vector<bool>> visited;

bool OutOfBounds(int n)
{
	if (n < 0 || n >= l) return true;
	return false;
}

void Solve()
{
	cin >> T;

	int cnt;

	while (T--)
	{
		cin >> l;
		visited.assign(l, vector<bool>(l, false));

		cin >> s >> t;
		start = { s, t };
		cin >> s >> t;
		target = { s, t };

		cnt = 0;

		q.push({ start, 0 });

		while (!q.empty())
		{
			pair<int, int> curPos = q.front().first;
			int curCnt = q.front().second;

			q.pop();

			if (curPos == target)
			{
				cout << curCnt << "\n";
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int ny = curPos.first + dy[i];
				int nx = curPos.second + dx[i];
				if (OutOfBounds(ny) || OutOfBounds(nx)) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = true;

				q.push({{ ny, nx }, curCnt + 1});
			}
		}

		visited.clear();
		while (!q.empty()) q.pop();
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}