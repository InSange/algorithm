#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    int left = 1, right = distance;
    
    while(left <= right)
    {
        int mid = (left + right)/2;
        int cnt = 0;
        int cur = 0;
        for(const auto& rock : rocks)
        {
            int dist = rock - cur;
            if(dist < mid)
            {
                cnt++;
            }
            else
            {
                cur = rock;
            }
        }
        
        if(cnt > n)
        {   
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            answer = mid;
        }
    }
    
    return answer;
}