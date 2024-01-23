#include<iostream>

using namespace std;

int N, M, S, E;
int arr[2001];
bool pal[2001][2001];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		pal[i][i] = true;
		if (i != 0 && arr[i] == arr[i - 1]) pal[i-1][i] = true;
	}

	for (int i = N - 3; i >= 0; i--)
	{
		for (int j = i + 2; j < N; j++)
		{
			if (arr[i] == arr[j] && pal[i + 1][j - 1]) pal[i][j] = true;
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;

		if (pal[S-1][E-1]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}