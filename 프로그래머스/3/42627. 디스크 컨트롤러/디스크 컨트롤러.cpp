#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

struct Cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];
    }
};

// 작업의 소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것 순
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime = 0;
    int curIndex = 0;
    int complete = 0;
    
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;
    
    while(complete < jobs.size())
    {
        while(curIndex < jobs.size() && curTime >= jobs[curIndex][0])
        {
            pq.push(jobs[curIndex]);
            curIndex++;
        }
        
        if(!pq.empty())
        {
            vector<int> curJob = pq.top();
            pq.pop();
            
            curTime += curJob[1];
            answer += (curTime-curJob[0]);
            complete++;
        }
        else
        {
            curTime = jobs[curIndex][0];
        }
    }
    
    return answer / jobs.size();
}