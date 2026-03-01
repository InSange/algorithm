#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C, ans;

vector<int> houses;

void Input()
{
	cin >> N >> C;

	houses.assign(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> houses[i];
	}
}

void Solve()
{
	ans = 0;
	sort(houses.begin(), houses.end());

	int left = 1, right = houses[N - 1] - houses[0];

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int curX = 0;
		int cnt = 1;
		for (int i = 1; i < N; i++)
		{
			if (mid <= houses[i] - houses[curX])
			{
				curX = i;
				cnt++;
			}
		}

		if (cnt >= C)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	cout << ans << "\n";

	return 0;
}