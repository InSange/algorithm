#include <iostream>
#include <algorithm>

using namespace std;

int R, G, B;

void Input()
{
	cin >> R >> G >> B;
}

void Solve()
{
	float r = R / 255.0f;
	float g = G / 255.0f;
	float b = B / 255.0f;

	float K = 1.0f - max({ r, g, b });

	float C, M, Y;

	if (K == 1.0f)
	{
		C = 0.0f;
		M = 0.0f;
		Y = 0.0f;
	}
	else
	{
		C = (1.0f - r - K) / (1.0f - K);
		M = (1.0f - g - K) / (1.0f - K);
		Y = (1.0f - b - K) / (1.0f - K);
	}

	cout << C << " " << M << " " << Y << " " << K;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}