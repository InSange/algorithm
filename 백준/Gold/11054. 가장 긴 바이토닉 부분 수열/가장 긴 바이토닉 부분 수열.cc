#include <iostream>
#include <vector>

using namespace std;

int N, val, ans;
vector<int> arr;
vector<int> dpFront;
vector<int> dpBack;

void Solve()
{
	ans = 0;
	cin >> N;

	dpFront.assign(N, 1);
	dpBack.assign(N, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> val;
		arr.push_back(val);
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dpFront[i] = max(dpFront[i], dpFront[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				dpBack[i] = max(dpBack[i], dpBack[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dpFront[i] + dpBack[i] - 1);
	}

	cout << ans << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}