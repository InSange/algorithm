#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<int> times;	// 포인트마다 걸린 시간
vector<int> visited;	// 점마다 방문한 수
queue<int> q;

bool OutOfBounds(int num)
{
	return (num < 0 || 100000 < num);
}

void Solve()
{
	times.assign(100001, 100001);
	visited.assign(100001, 0);
	cin >> N >> K;
	times[N] = 0;

	if (N > K || N == K)
	{
		cout << N - K << "\n" << 1;
		return;
	}

	q.push(N);

	while (!q.empty())
	{
		int curPoint = q.front();
		q.pop();

		for (int nextPoint : {curPoint + 1, curPoint - 1, 2 * curPoint})
		{
			if (OutOfBounds(nextPoint) || times[curPoint]+1 > times[K]) continue;

			if (visited[nextPoint] == 0)
			{
				visited[nextPoint] = 1;
				times[nextPoint] = times[curPoint] + 1;
				q.push(nextPoint);
			}
			else if (times[nextPoint] >= times[curPoint] + 1)
			{
				visited[nextPoint]++;
				q.push(nextPoint);
			}
		}
	}

	cout << times[K] << "\n" << visited[K];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}