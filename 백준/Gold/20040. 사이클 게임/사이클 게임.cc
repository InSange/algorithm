#include <iostream>
#include <vector>

using namespace std;

int n, m, num1, num2;
vector<int> parent;

int GetParent(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent[x]);
}

void UnionParent(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);

	if (a > b) parent[b] = a;
	else parent[a] = b;
}

bool FindParent(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);

	return (a == b ? true : false);
}

void Solve()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		parent.push_back(i);
	}

	for(int i = 1; i <= m; i++)
	{
		cin >> num1 >> num2;

		if (FindParent(num1, num2))
		{
			cout << i;
			return;
		}
		else
		{
			UnionParent(num1, num2);
		}
	}

	cout << 0;
	return;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}