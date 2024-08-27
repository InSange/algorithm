#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
vector<int> ans;
vector<int> start = { 2, 3, 5, 7 };

bool IsPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}

void DFS(int num, int depth)
{
	if (depth == N)
	{
		if (IsPrime(num)) ans.push_back(num);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		int next = num * 10 + i;
		if(IsPrime(next)) DFS(next, depth + 1);
	}
}

void Solve()
{
	cin >> N;

	for (int num : start) DFS(num, 1);

	for (int num : ans) cout << num << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}