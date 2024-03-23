#include <iostream>
#include <vector>

using namespace std;

const int MAX_INT = 9999999;
int N, M, X, n, m, t, answer;
vector<vector<int>> towns;

void Solve()
{
	
	cin >> N >> M >> X;

	answer = 0;
	towns.assign(N+1, vector<int>(N+1, MAX_INT));

	while (M--)
	{
		cin >> n >> m >> t;
		towns[n][m] = t;
	}

	for (int k = 1; k <= N; k++)
	{
		towns[k][k] = 0;
		for (int i = 1; i <= N; i++)
		{
			if (towns[i][k] == MAX_INT) continue;
			for (int j = 1; j <= N; j++)
			{
				towns[i][j] = min(towns[i][j], towns[i][k] + towns[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, towns[i][X] + towns[X][i]);
	}

	cout << answer << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}