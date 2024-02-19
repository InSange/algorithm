#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, M;
int low, high, cnt, len, answer;

void Solve()
{
	low = 1;
	high = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		high += num;
	}

	while (low <= high)
	{
		int mid = (low + high) / 2;
		cnt = 0;
		len = 0;

		bool flag = true;
		for (int i = 0; i < N; i++)
		{
			if (v[i] > mid)
			{
				flag = false;
				break;
			}
			if (v[i] > len)
			{
				len = mid;
				cnt++;
				if (cnt > M)
				{
					flag = false;
					break;
				}
			}
			len -= v[i];
		}

		if (flag)
		{
			answer = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
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