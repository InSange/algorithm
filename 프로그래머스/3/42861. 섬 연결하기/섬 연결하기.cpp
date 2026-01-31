#include <string>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 1. 인접 리스트 생성
    vector<vector<pii>> adj(n);
    for(const auto& cost : costs) {
        adj[cost[0]].push_back({cost[2], cost[1]});
        adj[cost[1]].push_back({cost[2], cost[0]});
    }
    
    // 2. Prim 알고리즘 준비
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n, false);
    
    // 임의의 시작점 (0번 노드)
    pq.push({0, 0}); // {비용, 노드}
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        // 이미 연결된 섬이면 패스
        if(visited[cur]) continue;
        
        // [핵심] 연결 확정! 여기서 바로 비용 더하기
        visited[cur] = true;
        answer += cost;
        
        // 다음 간선 탐색
        for(const auto& next : adj[cur]) {
            int next_cost = next.first;
            int next_node = next.second;
            
            // [최적화] 이미 방문한(연결된) 노드로 가는 간선은 굳이 큐에 넣지 않음
            if(!visited[next_node]) {
                pq.push({next_cost, next_node});
            }
        }
    }
    
    return answer;
}