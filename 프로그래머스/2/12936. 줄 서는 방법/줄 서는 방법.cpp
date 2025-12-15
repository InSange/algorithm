#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long fac(int n)
{
    if(n < 2) return n;
    return n * fac(n-1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> humans;
    
    for(int i = 1; i <= n; i++)
    {
        humans.push_back(i);
    }
    
    int nmg = n;
    k--;
    while(answer.size() != n)
    {
        if(nmg == 1)
        {
            answer.push_back(humans[0]);
            break;
        }
        long long facto = fac(nmg-1);
        int index = (k == 0 ? 0 : k/facto);
        
        answer.push_back(humans[index]);
        humans.erase(humans.begin() + index);
        
        k = k%facto;
        nmg--;
    }
    
    return answer;
}

/* 시간 초과 -> 20!는 2,432,902,008,176,640,000개가 나옴. dfs로 다 탐색하기에는 무리.
void dfs(int n, vector<bool>& visited, vector<vector<int>>& v, vector<int>& temp, int cnt)
{
    if(temp.size() == n)
    {
        v.push_back(temp);
        return;
    }
    
    for(int i = 1; i <=n; i++)
    {
        if(visited[i]) continue;
        temp.push_back(i);
        visited[i] = true;
        dfs(n, visited, v, temp, cnt + 1);
        temp.pop_back();
        visited[i] = false;
    }
}
// dfs방식으로 순차적으로
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<vector<int>> v;
    vector<int> temp;
    vector<bool> visited(n+1, false);
    
    dfs(n, visited, v, temp, 0);
    
    answer = v[k-1];
    return answer;
}
*/