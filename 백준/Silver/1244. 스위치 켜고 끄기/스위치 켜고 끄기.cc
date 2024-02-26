#include <iostream>
#include <vector>

using namespace std;

vector<int> switchs;
int len, l, r, man, n, mlen;

void Input()
{
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> n;
		switchs.push_back(n);
	}
	cin >> mlen;
}

void Solve()
{
	while (mlen--)
	{
		cin >> man >> n;

		if (man == 1)
		{
			for (int i = 1; i * n <= len; i++)
			{
				switchs[n*i - 1] = (switchs[n*i - 1] + 1) % 2;
			}
		}
		else// if(man == 2)
		{
			n--;
			switchs[n] = (switchs[n] + 1) % 2;
			l = n - 1;
			r = n + 1;

			while (l >= 0 && r < len)
			{
				if (switchs[l] == switchs[r])
				{
					switchs[l] = (switchs[l] + 1) % 2;
					switchs[r] = (switchs[r] + 1) % 2;
					l--;
					r++;
				}
				else if (switchs[l] != switchs[r])
				{
					break;
				}
			}
		}
	}

	int index = 0;
	while (index < len)
	{
		cout << switchs[index] << " ";
		index++;
		if (index % 20 == 0) cout << "\n";
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