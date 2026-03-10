#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
vector<vector<int>> students;
vector<int> indgree;

void Input()
{
	cin >> N >> M;

	students.assign(N + 1, vector<int>());
	indgree.assign(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;

		students[A].push_back(B);
		indgree[B]++;
	}

	queue<int> q;
	
	for (int i = 1; i < N + 1; i++)
	{
		if (indgree[i] == 0) q.push(i);
	}

	vector<int> answer;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		answer.push_back(cur);

		for (int i = 0; i < students[cur].size(); i++)
		{

			indgree[students[cur][i]]--;
			if (indgree[students[cur][i]] == 0) q.push(students[cur][i]);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();

	return 0;
}