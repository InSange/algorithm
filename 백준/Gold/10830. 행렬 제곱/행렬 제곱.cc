#include <iostream>

using namespace std;

int N, i, j, t, k;
long long  A[6][6], ans[6][6], temp[6][6];
long long B;

void Input()
{
	cin >> N >> B;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
		ans[i][i] = 1;
	}
}

void Matrix_Multi(long long a[6][6], long long b[6][6])
{
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				temp[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			a[i][j] = temp[i][j] % 1000;
			temp[i][j] = 0;
		}
	}
}

void Solve()
{
	do
	{
		if (B % 2 == 1) Matrix_Multi(ans, A);
		Matrix_Multi(A, A);
	} while (B /= 2);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}