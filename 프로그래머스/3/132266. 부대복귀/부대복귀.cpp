#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// des에서 dfs로 거리 업데이트
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> visited(n + 1, -1);
    vector<vector<int>> dist(n + 1, vector<int>());
    
    for(vector<int> road : roads)
    {
        dist[road[0]].push_back(road[1]);
        dist[road[1]].push_back(road[0]);
    }
    
    queue<int> q;
    q.push(destination);
    visited[destination] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int next : dist[cur])
        {
            if(visited[next] != -1) continue;
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
    
    for(int s : sources)
    {
        answer.push_back(visited[s]);
    }
    
    return answer;
}