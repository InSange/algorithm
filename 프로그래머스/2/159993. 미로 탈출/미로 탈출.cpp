#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int col;
int row;

bool boundCheck(int y, int x)
{
    return (y >= 0 && y < row && x >= 0 && x < col);
}

int solution(vector<string> maps) {
    int answer = 0;
    bool canEscape = false;
    
    col = maps[0].size();
    row = maps.size();
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    queue<pair<int, int>> q;
    vector<vector<int>> visited;
    visited.assign(row, vector<int>(col, 99999));
    
    pair<int, int> startPos;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(maps[i][j] == 'S')
            {
                startPos = {i, j};
                break;
            }
        }
    }
    
    visited[startPos.first][startPos.second] = 0;
    q.push(startPos);
    
    // 레버 찾기
    while(!q.empty())
    {
        pair<int, int> cur;
        cur = q.front();
        q.pop();
        bool isException = false;
        for(int i = 0; i < 4; i++)
        {   // 예외는 왼쪽 레버있고 오른쪽 탈출 지점일 때. 레버 먼저 방문하고 탈출 지점을 탐색해버림.
            if(isException) continue;
            int nextY = cur.first + dy[i];
            int nextX = cur.second + dx[i];
            
            if(!boundCheck(nextY, nextX)) continue; // 경계 걸러지고
            if(maps[nextY][nextX] == 'X') continue; // X 걸러지고
            int cost = visited[cur.first][cur.second];
            if(cost + 1 >= visited[nextY][nextX]) continue; // 비용 산출
            if(maps[nextY][nextX] == 'L' && !canEscape) // 레버라면
            {
                canEscape = true; // 레버를 당김
                visited.assign(row, vector<int>(col, 99999)); // 지도 초기화
                while(!q.empty()) q.pop(); // 출발지점은 레버부터.
                isException = true;
            }
            else if(maps[nextY][nextX] == 'E' && canEscape) // 도착지라면
            {
                answer = cost+1;
                break;
            }
            visited[nextY][nextX] = cost+1;
            q.push({nextY, nextX});
        }
        
        if(answer) break;
    }
    
    return answer ? answer : -1;
}