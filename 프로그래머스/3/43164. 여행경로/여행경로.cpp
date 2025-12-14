#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
int allCnt = 0;
vector<bool> visited;
bool f = false;

void dfs(string cur, vector<vector<string>>& tickets, int cnt)
{
    if(cnt == allCnt) 
    {
        f = true;
        return ;
    }
    
    for(int i = 0; i < allCnt; i++)
    {
        if(visited[i]) continue;
        if(cur != tickets[i][0]) continue;
        
        visited[i] = true;
        dfs(tickets[i][1], tickets, cnt + 1);
        if(f)
        {
            answer.push_back(tickets[i][1]);
            return;
        }
        visited[i] = false;
    }
}

// 항공권을 모두 사용 = 모든 도시를 방문했다!
vector<string> solution(vector<vector<string>> tickets) {
    allCnt = tickets.size();
    visited.assign(allCnt, false);
    
    sort(tickets.begin(), tickets.end()); // 알파벳 순서 정렬
    
    dfs("ICN", tickets, 0);
    answer.push_back("ICN");
    reverse(answer.begin(), answer.end());
    
    return answer;
}