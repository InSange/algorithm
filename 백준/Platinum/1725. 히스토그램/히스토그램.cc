#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, n, h, w, ans;
vector<int> v;
stack<int> st;

void Solve()
{
	cin >> N;
	ans = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	v.push_back(-1);
	N++;

	for (int i = 0; i < N; i++)
	{
		while (!st.empty() && v[st.top()] > v[i])
		{
			h = v[st.top()];
			st.pop();
			w = i;

			if (!st.empty()) w = i - st.top() - 1;

			ans = max(ans, h * w);
		}

		st.push(i);
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}