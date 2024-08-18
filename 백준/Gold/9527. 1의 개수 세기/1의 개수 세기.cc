#include <iostream>
#include <vector>

using namespace std;

long long bitArray[56];
long long A, B;

long long OneFind(long long n)
{
	long long val = n & 1;	// base 1 = 1
	long long tmp = n;

	int start = 0;
	while (tmp)
	{
		tmp /= 2;
		start++;
	}

	for (int i = start; i > 0; i--)
	{
		if (n & ((long long)1 << i))
		{
			long long bitVal = (long long)1 << i;
			val += bitArray[i - 1] + n - bitVal + 1;
			n -= bitVal;
		}
	}

	return val;
}

void Solve()
{
	cin >> A >> B;

	bitArray[0] = 1;
	for (int i = 1; i <= 55; i++)
	{
		bitArray[i] = bitArray[i - 1] * 2 + ((long long)1 << i);
	}

	cout << OneFind(B) - OneFind(A - 1) << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}