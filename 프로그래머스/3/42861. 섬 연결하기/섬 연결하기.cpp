#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pii>> v(n, vector<pii>());
    vector<int> dist(n, 1e9);
    vector<bool> visited(n, false);
    
    for(const auto& cost : costs)
    {   // 0번 지점 <- 비용, 1번지점
        v[cost[0]].push_back({cost[2], cost[1]});
        v[cost[1]].push_back({cost[2], cost[0]});
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0, 0});
    
    while(!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        
        if(visited[cur.second]) continue;
        visited[cur.second] = true;
        dist[cur.second] = cur.first;
        
        for(const auto& bridge : v[cur.second])
        {
            if(dist[bridge.second] <= bridge.first) continue;
            pq.push(bridge);
        }
    }
    
    for(const int& d : dist)
    {
        answer += d;
    }
    
    return answer;
}