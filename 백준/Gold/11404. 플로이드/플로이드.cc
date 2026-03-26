#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, c;
vector<vector<int>> cities;

void Input()
{
	cin >> n >> m;

	cities.assign(n + 1, vector<int>(n + 1, 1e9));

	for (int i = 1; i < n + 1; i++)
	{
		cities[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		cities[a][b] = min(cities[a][b], c);
	}
}

void Solve()
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			for (int k = 1; k < n + 1; k++)
			{
				cities[j][k] = min(cities[j][k], cities[j][i] + cities[i][k]);
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (cities[i][j] == 1e9)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << cities[i][j] << " ";
			}
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}