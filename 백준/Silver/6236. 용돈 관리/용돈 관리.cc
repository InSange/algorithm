#include <iostream>
#include <vector>

using namespace std;

int N, M;
int low, high, mid, cnt, money, answer;
vector<int> v;

void Init()
{
	low = 1;
	high = 0;
	money = 0;
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		high += num;
	}
}

void Solve()
{
	Init();

	while (low <= high)
	{
		mid = (low + high)/2;
		cnt = 0;
		money = 0;
		bool flag = true;

		for (int i = 0; i < N; i++)
		{	// 소비해야하는 돈이 용돈보다 높을 때
			if (v[i] > mid)
			{
				flag = false;
				break;
			}
			if (money < v[i])
			{	// 작으면 충전
				money = mid;
				cnt++;
				if (cnt > M)
				{	// 횟수가 M보다 크다면 정확히 못 맞춤
					flag = false;
					break;
				}
			}
			money -= v[i];
		}

		if (flag)
		{
			answer = mid;
			high = mid-1;
		}
		else low = mid+1;
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