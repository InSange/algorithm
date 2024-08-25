#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> childs;
vector<int> pCnt;

void Solve()
{
	cin >> N >> M;
	childs.assign(N + 1, vector<int>());
	pCnt.assign(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int n1, n2;

		cin >> n1 >> n2;

		childs[n1].push_back(n2);
		pCnt[n2]++;
	}

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (pCnt[i] == 0) q.push(i);
	}

	vector<int> ans;

	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		ans.push_back(n);

		for (int num : childs[n])
		{
			pCnt[num]--;
			if (pCnt[num] == 0) q.push(num);
		}
	}

	for (int n : ans)
	{
		cout << n << " ";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}