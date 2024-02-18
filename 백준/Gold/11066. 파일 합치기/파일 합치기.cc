#include <iostream>
#include <cstring>

using namespace std;

int T, K, i;
long long ans;
long long dp[501][501];
int arr[501];
int sum[501];
const int MAX_VAL = 1000000000;

long long partition(int start, int end)
{
	if (start == end) return arr[start];

	long long& ref = dp[start][end];
	if (ref != -1) return ref;
	ref = MAX_VAL;

	for (int j = start; j < end; j++)
	{
		ref = min(ref, partition(start, j) + partition(j + 1, end));
		cout << start << ", " << end << ", " << j <<  " -> " << dp[start][end] << "\n";
	}
	ref += sum[end] - (start == 0 ? 0 : sum[start-1]);

	cout << start << ", " << end << " : " << dp[start][end] << "\n";
	return ref;
}

void Solve()
{
	cin >> T;

	while (T--)
	{
		cin >> K;
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));

		for (i = 0; i < K; i++)
		{
			cin >> arr[i];

			sum[i] = (i == 0) ? arr[i] : arr[i] + sum[i - 1];
		}
		ans = partition(0, K-1);
		cout << ans - sum[K-1]<< "\n";
	}
}

void Solve2()
{
	cin >> T;
	while (T--)
	{
		cin >> K;

		for (i = 1; i <= K; i++)
		{
			cin >> arr[i];
			sum[i] = arr[i] + sum[i - 1];
		}
		// 범위
		for (i = 1; i < K; i++)
		{	// start(j) ~
			for (int j = 1; j + i <= K; j++)
			{
				dp[j][j + i] = MAX_VAL;
				for (int k = j; k < j + i; k++)
				{
					dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j-1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	//Solve();
	Solve2();

	return 0;
}