#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> office;
vector<vector<vector<int>>> cctvDir = { // [cctv번호][회전상태][뻗어나갈_방향들]
    {{}},
    { {0}, {1}, {2}, {3} }, // 1번 CCTV
    { {0, 2}, {1, 3} }, // 2번 CCTV
    { {0, 1}, {1, 2}, {2, 3}, {3, 0} }, // 3번 CCTV
    { {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} }, // 4번 CCTV
    { {0, 1, 2, 3} } // 5번 CCTV
};
vector<vector<int>> cctvs;

int N, M, ans = 1e9;
// 상 우 하 좌
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Input()
{
    cin >> N >> M;

    office.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> office[i][j];
            if (office[i][j] > 0 && office[i][j] < 6)
            {
                cctvs.push_back({ i, j });
            }
        }
    }
}

void DFS(int cur)
{
    if (cur == cctvs.size())
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (office[i][j] == 0) sum++;
            }
        }

        ans = min(ans, sum);
        return;
    }

    int curY = cctvs[cur][0];
    int curX = cctvs[cur][1];
    int curNum = office[curY][curX];

    // cctv 번호에 있는 상태 개수
    for (int i = 0; i < cctvDir[curNum].size(); i++)
    {   // 뻗어 나갈 방향 개수
        vector<vector<int>> temp(office);
        for (int j = 0; j < cctvDir[curNum][i].size(); j++)
        {
            int n = cctvDir[curNum][i][j];
            int nY = curY + dy[n];
            int nX = curX + dx[n];
            while (nY >= 0 && nX >= 0 && nY < N && nX < M && (office[nY][nX] != 6))
            {   // 빈 공간이면 -1로 변경하고 cctv가 있으면 패스
                if (office[nY][nX] == 0) office[nY][nX] = -1;
                nY += dy[n];
                nX += dx[n];
            }
        }
        DFS(cur + 1);
        office = temp;
    }
}

void Solve()
{
    DFS(0);
    cout << ans;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
    Solve();

	return 0;
}