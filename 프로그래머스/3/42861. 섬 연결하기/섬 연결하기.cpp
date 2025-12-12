#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
using pii = pair<int, int>;


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> islands;
    vector<vector<int>> bridge;
    vector<bool> visited;
    islands.assign(100, vector<int>(100, 0)); // 섬과 섬 사이의 코스트
    bridge.assign(100, vector<int>()); // 섬과 섬을 잇는 다리
    visited.assign(n, false); // 방문한 최솟 값
    
    cout << visited.size() << ", " << visited[0] << "\n";
    
    for(auto cost : costs)
    {
        int i1 = cost[0], i2 = cost[1], c = cost[2];
        islands[i1][i2] = c;
        islands[i2][i1] = c;
        bridge[i1].push_back(i2);
        bridge[i2].push_back(i1);
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 탐색할 섬의 인덱스
    pq.push({0, 0});
    
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(visited[cur]) continue;
        answer += cost;
        visited[cur] = true;
        //cout << "cur : " << cur << ", cost : " << cost << "\n";
        
        for(auto b : bridge[cur])
        {
            if(visited[b]) continue;

            pq.push({islands[cur][b], b});
            //cout << "push data { " << b << ", cost : " << islands[cur][b] << "} \n";
        }
    }
    
    return answer;
}