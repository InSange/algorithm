#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void Solve()
{ // 누적합 + 이분탐색 접근?
	int N, S;
	cin >> N >> S;

	vector<int> nums(N);
	for (int i = 0; i < N; i++) cin >> nums[i];

	int left = 0, right = 0;
	int sum = 0;
	int answer = INT_MAX;

	for (; right < N; right++)
	{
		sum += nums[right];

		while (sum >= S)
		{
			answer = min(answer, right - left + 1);

			sum -= nums[left++];
		}
	}

	if (answer == INT_MAX) cout << 0 << "\n";
	else cout << answer << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}