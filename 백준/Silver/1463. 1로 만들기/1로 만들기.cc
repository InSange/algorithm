#include <iostream>

using namespace std;

int dp[1000001] = { 0, 0, 1, 1 };

int main()
{
	int N;
	cin >> N;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N];

	return 0;
}