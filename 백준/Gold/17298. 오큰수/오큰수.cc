#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void Solve()
{
	vector<int> v;
	int N, num;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	vector<int> answer;
	stack<int> st;
	int index = N - 1;
	st.push(v[index]);
	answer.push_back(-1);

	index--;

	for (; index >= 0; index--)
	{
		if (st.empty()) answer.push_back(-1);
		else
		{
			while (!st.empty())
			{
				if (st.top() <= v[index]) st.pop();
				else
				{
					answer.push_back(st.top());
					break;
				}
			}

			if(st.empty()) answer.push_back(-1);
		}
		st.push(v[index]);
	}

	reverse(answer.begin(), answer.end());

	for (const int& n : answer) cout << n << " ";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}