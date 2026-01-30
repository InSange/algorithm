#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

struct cmp
{
    bool operator() (const pii& a, const pii& b)
    {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, priority_queue<pii, vector<pii>, cmp>> um;
    unordered_map<string, int> umCnt;
    
    for(int i = 0; i < genres.size(); i++)
    {
        um[genres[i]].push({plays[i], i});
        umCnt[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> v(umCnt.begin(), umCnt.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b)
         {
             return a.second > b.second;
         });
    
    for(auto data : v)
    {
        int cnt = 0;
        while(!um[data.first].empty())
        {
            if(cnt == 2) break;
            answer.push_back(um[data.first].top().second);
            um[data.first].pop();
            cnt++;
        }
    }
    
    return answer;
}