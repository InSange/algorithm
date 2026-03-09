#include <iostream>
#include <vector>

using namespace std;

int N, K, W, V;
vector<int> dp;
vector<vector<int>> v;

void Input()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> W >> V;

		v.push_back({ W, V });
	}

	dp.assign(K + 1, 0);
}

void Solve()
{
	for (int i = 0; i < N; i++)
	{
		W = v[i][0], V = v[i][1];

		for (int j = K; j >= W; j--)
		{
			dp[j] = max(dp[j], dp[j - W] + V);
		}
	}

	cout << dp[K] << "\n";
}

int main()
{
	Input();
	Solve();

	return 0;
}