#include <iostream>

using namespace std;

long long N, price;
long long city[100002];
long long dis[100002];
long long cnt = 0;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> dis[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> city[i];
	}

	price = city[0];

	for (int i = 1; i < N; i++)
	{
		if (i == N - 1)
		{
			cnt += price * dis[i];
		}
		else
		{
			cnt += price * dis[i];
			if (price > city[i])
			{
				price = city[i];
			}
		}
	}

	cout << cnt;

	return 0;
}