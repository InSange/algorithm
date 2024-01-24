#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, n, front, last, i, j;
string p, x, num;
vector<int> v;
bool removeFront, pass;

void Solve()
{
	cin >> T;

	while (T--)
	{
		v.clear();
		num = "";
		removeFront = true;
		
		cin >> p >> n >> x;
		
		for (i = 0; i < x.length(); i++)
		{
			if (x[i] >= '0' && x[i] <= '9')
			{
				num += x[i];
			}
			else if (x[i] == ',' || x[i] == ']' && num != "")
			{
				v.push_back(stoi(num));
				num = "";
			}
		}

		pass = true;
		front = 0, last = v.size();

		for (i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
			{
				removeFront = (removeFront ? false : true);
			}
			else
			{
				if (front == last)
				{
					cout << "error" << "\n";
					pass = false;
					break;
				}
				if (removeFront) front++;
				else last--;
			}
		}

		if (pass)
		{
			vector<int> ans;
			int len = last - front;

			cout << "[";
			for (i = 0; i < len; i++)
			{
				cout << (removeFront ? v[front++] : v[--last]);				
				if (i != len-1) cout << ",";
			}
			cout << "]\n";
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}