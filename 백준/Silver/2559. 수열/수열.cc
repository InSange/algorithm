#include <iostream>
#include <vector>

using namespace std;

void Solve()
{
	int N, K, sum = 0, answer = -100000000;
	cin >> N >> K;

	vector<int> v(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];

		sum += v[i];
		if (i >= K)
		{
			sum -= v[i - K];
			answer = max(answer, sum);
		}
	}

	cout << answer << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Solve();

	return 0;
}