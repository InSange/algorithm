#include<iostream>
#include<vector>

using namespace std;

void Solve()
{
	int N, M, num;
	long long answer = 0, sum = 0;

	cin >> N >> M;

	vector<long long> cnt(M, 0);
	cnt[0] = 1;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		sum += num;
		cnt[sum % M]++;
	}

	for (int i = 0; i < M; i++)
	{
		answer += (cnt[i] * (cnt[i] - 1) / 2);
	}

	cout << answer << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}