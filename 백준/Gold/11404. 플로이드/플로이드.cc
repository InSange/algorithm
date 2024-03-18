#include <iostream>
#include <vector>

using namespace std;

const int INF = 99999999;
int n, m, a, b, c;
vector<vector<int>> cities;

void Solve()
{
	cin >> n >> m;
	n++;
	cities.assign(n, vector<int>(n, INF));

	for (int i = 1; i < n; i++)
	{
		cities[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		if (cities[a][b] < c) continue;
		cities[a][b] = c;
	}

	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				cities[i][j] = min(cities[i][k] + cities[k][j], cities[i][j]);
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << (cities[i][j] == INF ? 0 : cities[i][j]) << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}