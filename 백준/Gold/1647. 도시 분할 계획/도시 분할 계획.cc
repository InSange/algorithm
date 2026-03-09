#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, M, A, B, C;

//vector<vector<int>> villages;
vector<int> parents;

priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
stack<int> bridges;	// 연결된 다리를 저장

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;

		pq.push({ C, A, B });
	}

	parents.resize(N + 1);

	for (int i = 0; i < N + 1; i++)
	{
		parents[i] = i;
	}
}

int GetParent(int x)
{
	if (x == parents[x]) return x;
	return parents[x] = GetParent(parents[x]);
}

bool IsParent(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);

	if (a == b) return true;

	if (a < b) parents[b] = a;
	else parents[a] = b;

	return false;
}

void Solve()
{
	while (!pq.empty())
	{
		A = pq.top()[1], B = pq.top()[2]; // 마을 1, 2
		C = pq.top()[0];	// 비용

		pq.pop();

		if (IsParent(A, B)) continue;

		bridges.push(C);
	}

	int answer = 0;
	bridges.pop();	// 가장 마지막에 연결한 다리 비용

	while (!bridges.empty())
	{
		answer += bridges.top();
		bridges.pop();
	}

	cout << answer << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}