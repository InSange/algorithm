#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct j_info
{
	int m;	// 보석 무게
	int v;		// 보석 가치
	j_info(int _m, int _v)
	{
		m = _m;
		v = _v;
	}
};

int N, K;
long answer;
vector<j_info> jewel;
vector<int> backpack;
priority_queue<int> pq;

bool cmp(const j_info& a, const j_info& b)
{
	if (a.m > b.m) return false;
	else if (a.m == b.m)
	{
		if (a.v > b.v) return false;
		else if (a.v == b.v) return false;
	}
	else return true;
}

void Solve()
{
	answer = 0;
	cin >> N >> K;

	int m, v, c;
	for (int i = 0; i < N; i++)
	{
		cin >> m >> v;
		jewel.push_back(j_info(m, v));
	}

	for (int i = 0; i < K; i++)
	{
		cin >> c;
		backpack.push_back(c);
	}

	sort(jewel.begin(), jewel.end(), cmp);
	sort(backpack.begin(), backpack.end());

	int j = 0;
	for (int i = 0; i < K; i++)
	{
		while (j < N && backpack[i] >= jewel[j].m)
		{
			pq.push(jewel[j].v);
			j++;
		}

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}