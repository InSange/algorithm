#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> datas;
int n, d, h, o;

void Input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> h >> o;
		if (h > o) swap(h, o);
		datas.push_back({h, o});
	}

	cin >> d;
}

void Solve()
{	// 데이터 전처리
	vector<pair<int, int>> ppdatas;

	for (int i = 0; i < n; i++)
	{
		int len = datas[i].second - datas[i].first;
		if (d < len) continue;
		ppdatas.push_back(datas[i]);
	}

	sort(ppdatas.begin(), ppdatas.end(), [](const auto& a, const auto& b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
		});

	priority_queue<int, vector<int>, greater<int>> pq;
	int maxV = 0;
	int curEnd = 0;

	for (int i = 0; i < ppdatas.size(); i++)
	{
		curEnd = ppdatas[i].second;
		
		if (pq.empty()) pq.push(ppdatas[i].first);
		else
		{
			while(!pq.empty() && pq.top() < (curEnd - d)) 
				pq.pop();
			pq.push(ppdatas[i].first);
		}

		maxV = max(maxV, static_cast<int>(pq.size()));
	}

	cout << maxV;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}