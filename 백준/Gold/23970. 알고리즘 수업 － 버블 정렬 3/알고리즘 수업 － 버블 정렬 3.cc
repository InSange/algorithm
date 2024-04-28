#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, n;
vector<int> A;
unordered_map<int, int> B;

bool Check()
{
	for (int i = 1; i < N; i++)
	{
		if (i != B[A[i]]) return false;
	}
	return true;
}

void Solve()
{
	cin >> N;
	N += 1;
	A.assign(N, 0);

	for (int i = 1; i < N; i++)
	{
		cin >> n;
		A[i] = n;
	}

	for (int i = 1; i < N; i++)
	{
		cin >> n;
		B[n] = i;
	}

	if (Check())
	{
		cout << 1;
		return;
	}

	int fix = N-1;
	int fix2 = 0;
	for (int j = 1; j < N-1; j++)
	{
		if (fix == 0) break;
		int check = 0;

		for (int i = 1; i < fix; i++)
		{
			if (A[i] <= A[i + 1]) continue;

			swap(A[i], A[i + 1]);
			fix2 = i;
			check++;

			if (i+1 == B[A[i+1]] && Check())
			{
				cout << 1;
				return;
			}
		}
		fix = fix2;
		if (check == 0) break;
	}

	cout << 0;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}