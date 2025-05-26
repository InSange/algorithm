#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int cur = 0;
    queue<pair<int, int>> q; // 서버 종료되는 시간
    
    for(int i = 0; i < players.size(); i++)
    {
        if(!q.empty() && q.front().first <= i)
        {
            cur-= q.front().second;
            q.pop();
        }
        int curPlayers = players[i];
        int needServer = curPlayers/m;
        int serverSize = cur * m;
        int needSize = 0;
        
        if(curPlayers > 0 && (needServer * m) >= serverSize)
        {
            needSize = needServer-cur;
            q.push({i+k, needSize});
            answer += needSize;
            cur += needSize;
        }
        //cout << i << " : " << cur << " : " << needSize << "\n";
    }
    
    return answer;
}