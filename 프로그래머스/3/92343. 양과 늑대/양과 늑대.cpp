#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxSheep = 0;

void dfs(vector<int>& info, vector<vector<int>>& graph, int current, int sheep, int wolf, vector<int> next_nodes) {
    
    if (info[current] == 0) sheep++;
    else wolf++;

    if (wolf >= sheep) return;

    maxSheep = max(maxSheep, sheep);
    
    vector<int> next_candidates = next_nodes;
    auto it = find(next_candidates.begin(), next_candidates.end(), current);
    if(it != next_candidates.end()) next_candidates.erase(it);
    
    for(auto& v : graph[current])
    {
        next_candidates.push_back(v);
    }

    for (int next : next_candidates) {
        dfs(info, graph, next, sheep, wolf, next_candidates);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> graph(info.size(), vector<int>());
    
    for(auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
    }
    
    dfs(info, graph, 0, 0, 0, vector<int>());
    
    return maxSheep;
}