#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int MAX_INT = 9999999;

int N, K;
pair<int, int> visited[100001];
queue<int> q;
stack<int> st;

bool Check(int index)
{
	if (index < 0 || index > 100000) return false;
	return true;
}

void Init()
{	// 수빈이(N : 출발지)와 동생(K : 목적지) 값 설정
	cin >> N >> K;
	// 0 번째 인덱스도 범위에 속하기 때문에 MAX_INT로 초기화 해준다.
	// 첫번째 값은 해당 번호를 방문하기 이전의 번호를 저장하고, 두번째 값은 해당 번호로 오기까지의 횟수를 저장한다.
	for (int i = 0; i < 100001; i++)
	{
		visited[i] = { MAX_INT, MAX_INT };
	}
	visited[N] = { N, 0 };
}

void Solve()
{	
	if (N == K)
	{
		cout << visited[N].second << "\n" << N;
		return;
	}
	else if (N > K)
	{
		cout << N-K << "\n";
		while (N != K)
		{
			cout << N << " ";
			N--;
		}
		cout << N << "\n";
		return;
	}
	// 수빈이(N: 출발지) 값을 넣어준다.
	q.push(N);

	while (!q.empty())
	{
		int cur_num = q.front();
		//cout << cur_num << "\n";
		q.pop();

		int cur_cnt, next_num;
		cur_cnt = visited[cur_num].second;

		next_num = cur_num - 1;
		if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
		{
			q.push(next_num);
			visited[next_num].first = cur_num;
			visited[next_num].second = cur_cnt + 1;
		}
		if (next_num == K) break;
		next_num = cur_num + 1;
		if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
		{
			q.push(next_num);
			visited[next_num].first = cur_num;
			visited[next_num].second = cur_cnt + 1;
		}
		if (next_num == K) break;
		next_num = 2*cur_num;
		if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
		{
			q.push(next_num);
			visited[next_num].first = cur_num;
			visited[next_num].second = cur_cnt + 1;
		}
		if (next_num == K) break;
	}

	cout << visited[K].second << "\n";
	do {
		st.push(K);
		K = visited[K].first;
	} while (K != N);
	st.push(N);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Init();
	Solve();

	return 0;
}