#include <string>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

void dijkstra(vector<int>& result, const vector<vector<pii>>& graph, int start)
{
    auto cmp = [](const pii& a, const pii& b) {
        return a.second > b.second; // 비용 기준
    };
    
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    pq.push({start , 0}); // 인덱스, 비용
    
    result[start] = 0;
    
    while(!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        
        if (result[cur.first] < cur.second) continue;
        
        for(int i = 0; i < graph[cur.first].size(); i++)
        {
            pii next = graph[cur.first][i];
            
            if(result[next.first] > cur.second + next.second)
            {
                result[next.first] = cur.second + next.second;
                pq.push({next.first, result[next.first]});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    
    vector<vector<pii>> graph(n + 1);
    
    for(int i = 0; i < fares.size(); i++)
    {
        graph[fares[i][0]].push_back({fares[i][1], fares[i][2]}); // 인덱스, 요금
        graph[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    vector<vector<int>> results(3, vector<int>(n+1, 1e9));
    
    dijkstra(results[0], graph, s);
    dijkstra(results[1], graph, a);    
    dijkstra(results[2], graph, b);
    
    for(int i = 1; i <= n; i++)
    {
        if(results[0][i] == 1e9 || results[1][i] == 1e9 || results[2][i] == 1e9) continue;
        answer = min(answer, results[0][i] + results[1][i] + results[2][i]);
    }
    
    return answer;
}