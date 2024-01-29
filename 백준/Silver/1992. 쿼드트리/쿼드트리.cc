#include <iostream>

using namespace std;

int N, i, j;
string n;
int arr[100][100];

void Input()
{
	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> n;
		for (j = 0; j < N; j++)
		{
			arr[i][j] = n[j] - '0';
		}
	}
}

void Check(int arr_size, int y, int x)
{
	bool zero, one;
	zero = false;
	one = false;

	for (i = y; i < y+arr_size; i++)
	{
		for (j = x; j < x+arr_size; j++)
		{
			if (arr[i][j] == 0) zero = true;
			else one = true;

			if (zero && one)
			{
				cout << "(";
				int nextSize = arr_size / 2;
				Check(nextSize, y, x);
				Check(nextSize, y, x+nextSize);
				Check(nextSize, y + nextSize, x);
				Check(nextSize, y + nextSize, x + nextSize);
				cout << ")";
				return;
			}
		}
	}
	
	if (zero) cout << 0;
	else cout << 1;
}

void Solve()
{
	Check(N, 0, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}