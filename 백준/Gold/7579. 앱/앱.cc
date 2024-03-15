#include <iostream>
#include <vector>

using namespace std;

vector<int> memory;
vector<int> app;
vector<int> cost;
int N, M, costSum;

void Input()
{
	costSum = 0;
	cin >> N >> M;

	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		app.push_back(n);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		cost.push_back(n);
		costSum += n;
	}

	memory.assign(costSum+1, 0);
}

int Solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = costSum; j >= 0; j--)
		{
			if (cost[i] > j) break;
			memory[j] = max(memory[j], memory[j - cost[i]] + app[i]);
		}
	}

	for (int i = 0; i <= costSum; i++)
	{
		if (memory[i] >= M) return i;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	cout <<  Solve();

	return 0;
}