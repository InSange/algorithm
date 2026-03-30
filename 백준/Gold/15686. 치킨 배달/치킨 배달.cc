#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<int> selected_chickens;

int N, M, answer = 1e9;

void Input()
{
	cin >> N >> M;
	int r;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> r;

			if (r == 0) continue;
			else if (r == 1) houses.push_back({ i + 1, j + 1 });
			else if (r == 2) chickens.push_back({ i + 1, j + 1 });
		}
	}
}

void DFS(int start, int cnt)
{
	if (cnt == M)
	{
		int sum = 0;

		for (int i = 0; i < houses.size(); i++)
		{
			int hY = houses[i].first, hX = houses[i].second;
			int dist = 1e9;

			for (int idx : selected_chickens)
			{
				int cY = chickens[idx].first, cX = chickens[idx].second;
				dist = min(dist, abs(hY - cY) + abs(hX - cX));
			}

			sum += dist;
		}

		answer = min(answer, sum);
		return;
	}
	
	for (int i = start; i < chickens.size(); i++)
	{
		selected_chickens.push_back(i);
		DFS(i + 1, cnt + 1);
		selected_chickens.pop_back();  
	}
}

void Solve()
{
	DFS(0, 0);

	cout << answer << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}