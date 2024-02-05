#include <iostream>
#include <cstring>

using namespace std;

int T, N, i, j;
long long maxV;
int arr[2][100001];
long long dp[2][100001];

void Solve()
{
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = arr[0][1] + arr[1][0];
	dp[1][1] = arr[1][1] + arr[0][0];
	maxV = max(dp[0][1], dp[1][1]);

	for (i = 2; i < N; i++)
	{
		dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);

		long long v = max(dp[0][i], dp[1][i]);
		maxV = max(maxV, v);
	}

	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));
}

void Input()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		Solve();
		cout << maxV << "\n";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();

	return 0;
}