#include<vector>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<vector<int> > maps)
{
    int row = maps.size(), col = maps[0].size();
    queue<pii> q;
    q.push({0, 0});
    
    while(!q.empty())
    {
        pii cur = q.front();
        q.pop();
        
        if(cur.first == row-1 && cur.second == col-1) return maps[row-1][col-1];
        
        for(int i = 0; i < 4; i++)
        {
            pii next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first < 0 || next.first >= row || next.second < 0 || next.second >= col) continue;
            if(maps[next.first][next.second] != 1) continue;
            
            maps[next.first][next.second] = maps[cur.first][cur.second] + 1;
            q.push(next);
        }
    }
    
    return -1;
}