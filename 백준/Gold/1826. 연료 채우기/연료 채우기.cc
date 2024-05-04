#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, a, b, L, P, answer = 0;
bool canGO = true;

vector<pair<int, int>> v; // first = 거리, second = 연료
priority_queue<int> pq;

void Solve()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	cin >> L >> P;
	v.push_back({ L, 0 });

	sort(v.begin(), v.end());

	int fuel = P;
	for (int i = 0; i < v.size(); i++)
	{
		if (fuel < v[i].first)
		{
			while (!pq.empty() && fuel < v[i].first)
			{
				fuel += pq.top();
				pq.pop();
				answer++;
			}
			if(fuel < v[i].first)	break;
		}
		//fuel += v[i].second;
		pq.push(v[i].second);
	}

	if (fuel >= L) cout << answer;
	else cout << -1;
}


int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}