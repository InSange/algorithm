#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bag[101][100001] = {};

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}

int MAX(int n1, int n2)
{
	if (n1 > n2) return n1;
	else return n2;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	vector<pair<int, int>> v;

	cin >> N >> K;
	v.push_back(make_pair(0, 0));

	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;

		v.push_back(make_pair(W, V));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (v[i].first > j)
			{
				bag[i][j] = bag[i - 1][j];
			}
			else
			{
				bag[i][j] = MAX(bag[i-1][j - v[i].first] + v[i].second, bag[i-1][j]);
			}
			//cout << bag[i][j] << " ";
		}
		//cout << "\n";
	}

	cout << bag[N][K] << "\n";

	return 0;
}