#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// des에서 dfs로 거리 업데이트
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> distances(n + 1, -1);
    vector<vector<int>> graph(n + 1, vector<int>());
    
    for(const vector<int>& road : roads)
    {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    queue<int> q;
    q.push(destination);
    distances[destination] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int next : graph[cur])
        {
            if(distances[next] != -1) continue;
            distances[next] = distances[cur] + 1;
            q.push(next);
        }
    }
    
    for(int s : sources)
    {
        answer.push_back(distances[s]);
    }
    
    return answer;
}