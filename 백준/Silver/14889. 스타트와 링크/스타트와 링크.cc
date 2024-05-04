#include<iostream>
#include <vector>

using namespace std;

const int MAX_INT = 987654321;

int N, answer;
vector<vector<int>> man;
vector<bool> visited;

void DFS(int cur, int cnt)
{
	if (cnt == N / 2)
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
			{
				if (visited[i] && visited[j])
				{
					start += man[i][j] + man[j][i];
				}
				else if (!visited[i] && !visited[j])
				{
					link += man[i][j] + man[j][i];
				}
			}
		}
		
		answer = min(answer, abs(start - link));
	}

	for (int i = cur+1; i < N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		DFS(i, cnt + 1);
		visited[i] = false;
	}
}

void Solve()
{
	cin >> N;
	N++;

	man.assign(N, vector<int>(N, 0));
	visited.assign(N, false);

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			cin >> man[i][j];
		}
	}

	answer = MAX_INT;

	visited[1] = true;
	DFS(1, 1);

	cout << answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}