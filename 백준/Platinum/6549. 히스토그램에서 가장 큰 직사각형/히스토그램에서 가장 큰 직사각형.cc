#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> v;
int N, i;

void Solve()
{
	while (true)
	{
		cin >> N;
		if (N == 0) return;

		long long minH, ans, len;

		for (i = 0; i < N; i++)
		{
			int val;
			cin >> val;
			v.push_back(val);
		}
		v.push_back(-1);
		N++;
		stack<int> st;
		ans = 0;

		for (i = 0; i < N; i++)
		{
			while (!st.empty() && v[st.top()] > v[i])
			{
				len = i;
				minH = v[st.top()];
				st.pop();

				if (!st.empty()) len = i - st.top() - 1;

				ans = max(ans, len * minH);
			}

			st.push(i);
		}
		cout << ans << "\n";
		v.clear();
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}