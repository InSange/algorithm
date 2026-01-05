#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long left = 1, right = (long long)times[times.size() - 1] * n;
    
    while(left <= right)
    {
        long long mid = (left + right)/2;
        long long sum = 0;
        
        for(const int& time : times)
        {
            sum += (mid / time);
        }
        
        if(sum < n)
        {
            left = mid + 1;
        }
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }
    
    return answer;
}