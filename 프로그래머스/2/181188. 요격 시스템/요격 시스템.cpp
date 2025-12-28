#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int lastEnd = -1;
    
    for(const auto& target : targets) {
        int s = target[0], e = target[1];
        
        if(s >= lastEnd)
        {
            answer++;
            lastEnd = e;
        }
    }
    
    return answer;
}