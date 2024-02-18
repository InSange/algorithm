#include <iostream>

using namespace std;

struct Mat
{
	int row;
	int col;
};

int N, r, c, i, j, k;
Mat arr[501];
int dp[501][501];
const int MAX_VAL = 1000000000;

void Solve()
{
	cin >> N;

	for (i = 1; i <= N; i++)
	{
		cin >> r >> c;
		arr[i].row = r;
		arr[i].col = c;
	}

	for (i = 1; i < N; i++)
	{
		for (j = 1; j + i <= N; j++)
		{
			dp[j][j + i] = MAX_VAL;
			for (k = j; k <= j + i; k++)
			{
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + (arr[j].row * arr[k].col * arr[j + i].col));
			}
		}
	}

	cout << dp[1][N];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}