#include <iostream>
#include <vector>

using namespace std;

vector<int> isParent;
int n, m, a, b, isUnion;

void Init()
{
	cin >> n >> m;
	
	isParent.assign(n+1, 0);

	for (int i = 0; i < n + 1; i++)
	{
		isParent[i] = i;
	}
}

int GetParent(int n1)
{
	if (isParent[n1] == n1) return n1;
	return isParent[n1] = GetParent(isParent[n1]);
}

void UnionParent(int n1, int n2)
{
	int p1 = GetParent(n1);
	int p2 = GetParent(n2);

	if (p1 < p2) isParent[p2] = p1;
	else isParent[p1] = p2;
}

bool FindParent(int n1, int n2)
{
	int p1 = GetParent(n1);
	int p2 = GetParent(n2);

	if (p1 == p2) return true;
	else return false;
}

void Solve()
{
	while (m--)
	{
		cin >> isUnion >> a >> b;

		if (isUnion)
		{
			bool result = FindParent(a, b);
			if (result)
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
		else
		{
			UnionParent(a, b);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Init();
	Solve();

	return 0;
}