#include <iostream>
#include <queue>

using namespace std;

int T, N, i, j;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void Solve()
{
	cin >> T;

	while (T--)
	{
		cin >> N;
		long long num, sum, answer = 0;

		for (i = 0; i < N; i++)
		{
			cin >> num;
			pq.push(num);
		}

		while (pq.size() > 1)
		{
			sum = 0;
			for (j = 0; j < 2; j++)
			{
				sum += pq.top();
				pq.pop();
			}
			answer += sum;
			pq.push(sum);
		}

		cout << answer << "\n";
		pq.pop();
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}