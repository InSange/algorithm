#include <iostream>
#include <vector>

using namespace std;

int N, num, ans;
vector<int> arr;
vector<int> dp;

void Solve()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		arr.push_back(num);
		dp.push_back(num);
	}

	ans = arr[0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}