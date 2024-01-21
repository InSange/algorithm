#include <iostream>

using namespace std;

int F, S, G, U, D;
bool visited[1000001] = {};

void Input()
{
	cin >> F >> S >> G >> U >> D;
}

void Solve()
{
	if ((D == 0 && S > G) || (U == 0 && S < G))
	{
		cout << "use the stairs" << "\n";
		return;
	}

	int cnt = 0;

	while (true)
	{
		if (visited[S])
		{
			cout << "use the stairs" << "\n";
			return;
		}
		else
		{
			visited[S] = true;
		}

		if (S == G)
		{
			cout << cnt << "\n";
			return;
		}

		if (S > G)
		{
			int next = S - D;
			if (next < 1)
			{
				if (S + U <= F)
				{
					S += U;
				}
			}
			else
			{
				S = next;
			}
		}
		else if (S < G)
		{
			int next = S + U;
			if (next > F)
			{
				if (S - D >= 1)
				{
					S -= D;
				}
			}
			else
			{
				S = next;
			}
		}

		cnt++;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}