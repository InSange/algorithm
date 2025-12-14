#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(string cur, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& route, int cnt)
{
    route.push_back(cur);
    
    if(cnt == visited.size()) return true;
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(visited[i]) continue;
        if(cur != tickets[i][0]) continue;
        
        visited[i] = true;
        if(dfs(tickets[i][1], tickets, visited, route, cnt + 1)) return true;
        
        route.pop_back();
        visited[i] = false;
    }
    
    return false;
}

// 항공권을 모두 사용 = 모든 도시를 방문했다!
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end()); // 알파벳 순서 정렬
    
    dfs("ICN", tickets, visited, answer, 0);
    
    return answer;
}