#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool OutBoundCheck(int nextX, int nextY, int& boundX, int& boundY)
{
    return (nextX < 0 || nextX >= boundX || nextY < 0 || nextY >= boundY);
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<string> board) {
    int rowCnt = board.size();
    int colCnt = board[0].size();
    
    vector<vector<int>> visited;
    visited.assign(rowCnt, vector<int>(colCnt, -1));
    
    pair<int, int> startPos, endPos;

    for(int i = 0; i < rowCnt; i++)
    {
        for(int j = 0; j < colCnt; j++)
        {
            if(board[i][j] == 'R') startPos = {i, j};
            else if(board[i][j] == 'G') endPos = {i, j};
        }
    }
    
    visited[startPos.first][startPos.second] = 0;
    queue<pair<int, int>> q;
    
    q.push(startPos);
    while(!q.empty())
    {
        pair<int, int> curPos = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nextY = curPos.first;
            int nextX = curPos.second;
            // 다음 방향이 D가 아니고 경계밖이 아니면 해당 방향으로 진행.
            while(!OutBoundCheck(nextX + dx[i], nextY + dy[i], colCnt, rowCnt) && board[nextY + dy[i]][nextX + dx[i]] != 'D' )
            {
                nextY += dy[i];
                nextX += dx[i];
            }
            
            if(visited[nextY][nextX] == -1)
            {
                visited[nextY][nextX] = visited[curPos.first][curPos.second] + 1;
                q.push({nextY, nextX});
            }
        }
    }
    
    return visited[endPos.first][endPos.second];
}