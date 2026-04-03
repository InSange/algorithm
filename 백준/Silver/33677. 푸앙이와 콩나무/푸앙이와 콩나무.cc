#include <iostream>
#include <queue>

using namespace std;

int days[1000005];
long long waters[1000005];

int N;

void Input()
{
	cin >> N;
}

void Solve()
{
	for (int i = 0; i <= 1000000; i++) {
		days[i] = -1;
		waters[i] = 2e18;
	}
	// 횟수 / 물 양 / 현재 높이
	queue<pair<int, pair<long long, long long>>> q;
	q.push({ 0, {0, 0 } });

	days[0] = 0;
	waters[0] = 0;

	while (!q.empty())
	{
		int cnt = q.front().first;
		long long water = q.front().second.first;
		long long curNum = q.front().second.second;
		
		q.pop();

		if (waters[curNum] < water) continue;
		if (days[N] != -1 && cnt > days[N]) break;
		
		long long next_lens[3] = { curNum + 1, curNum * 3, curNum * curNum };
		long long next_waters[3] = { water + 1, water + 3, water + 5 };

		for (int i = 0; i < 3; i++) {
			long long n_len = next_lens[i];
			long long n_water = next_waters[i];

			if (n_len > N) continue;

			if (days[n_len] == -1 || (days[n_len] == cnt + 1 && n_water < waters[n_len])) {
				days[n_len] = cnt + 1;
				waters[n_len] = n_water;
				q.push({ cnt + 1, {n_water, n_len} });
			}
		}
	}

	cout << days[N] << " " << waters[N];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}