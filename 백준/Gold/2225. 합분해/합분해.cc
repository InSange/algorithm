#include <iostream>

using namespace std;

int dp[201][201] = { 0 };

int main()
{
	int N, k;
	cin >> N >> k;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j])%1000000000;
		}
	}
	cout << dp[k-1][N];

	return 0;
}