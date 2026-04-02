#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;

int answer = 0;
int r, c;

// 이동 방향 - 0:위, 1:오른쪽, 2:아래, 3:왼쪽
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int next_dir[8][4] = { // 진입 해서 다음 방향
    {-1, -1, -1, -1}, // 0번 선로
    {-1, 1, -1, 3}, // 좌, 우 선로
    {0, -1, 2, -1}, // 위, 아래 선로
    {0, 1, 2, 3}, // 상하좌우 선로
    {-1, 0, 3, -1}, // 좌상 선로
    {-1, -1, 1, 0}, // 우상 선로
    {1, -1, -1, 2}, // 우하 선로
    {3, 2, -1, -1}, // 좌하 선로
};

void dfs(int curY, int curX, int dir)
{
    if(curY == r && curX == c) 
    {
        bool isValid = true;
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(board[i][j] == 3) {
                    // 3번 선로는 2번 방문되어 있어야함. 상하좌우 통과
                    if(visited[i][j] != 2) isValid = false;
                } else if(board[i][j] > 0) { // 3번 제외 일반 선로는 중복값이면 안됨
                    if(visited[i][j] != 1) isValid = false;
                }
            }
        }
        if(isValid) answer++;
        return;
    }
    
    int nextY = curY + dy[dir];
    int nextX = curX + dx[dir];
    
    if(nextY == 0 || nextX == 0 || nextY > r || nextX > c) return;

    int nextPoint = board[nextY][nextX];
    
    if(nextPoint == -1) return;
    
    if(visited[nextY][nextX] > 0) {
        if(nextPoint != 3) return; // 3번 선로가 아니면 재방문 절대 불가!
        if(visited[nextY][nextX] == 2) return; // 3번 선로라도 2번을 초과할 순 없음!
    }
    
    if(nextPoint == 0)
    {
        for(int i = 1; i < 8; i++)
        {
            int nextDir = next_dir[i][dir];
            
            if(nextDir == -1) continue;
            
            board[nextY][nextX] = i;
            visited[nextY][nextX]++;
            dfs(nextY, nextX, nextDir);
            visited[nextY][nextX]--;
            board[nextY][nextX] = 0;
        }
    }
    else
    {   // 이미 선로가 깔려있는 경우
        int nextDir = next_dir[nextPoint][dir]; // 선로 진입 방향 확인
        if(nextDir != -1) 
        {
            visited[nextY][nextX]++; 
            dfs(nextY, nextX, nextDir);
            visited[nextY][nextX]--; 
        }
    }
}

int solution(vector<vector<int>> grid) {

    r = grid.size();
    c = grid[0].size();
    
    board.assign(r + 1, vector<int>(c + 1, 0));
    visited.assign(r + 1, vector<int>(c + 1, 0));
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            board[i+1][j+1] = grid[i][j];
        }
    }
    
    visited[1][1] = 1;
    dfs(1, 1, 1);
    
    return answer;
}