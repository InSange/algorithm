#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

// 두번째 풀이 : 누적합 활용하기.
long long solution(vector<int> sequence) {
    long long p_sum = 0; // 현재까지의 누적 합
    long long max_p = 0; // 누적 합 중 최댓값 (초기값 0 포함)
    long long min_p = 0; // 누적 합 중 최솟값 (초기값 0 포함)
    
    int pulse = 1;
    
    for (int num : sequence) {
        p_sum += (long long)num * pulse;

        max_p = max(max_p, p_sum);
        min_p = min(min_p, p_sum);
        
        pulse *= -1; 
    }
    
    return max_p - min_p;
}

// 첫풀이 : +-, -+을 sequence에 적용시켜서 값을 비교해나가며 답을 찾음.
/*
long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<int> mp;
    vector<int> pm;
    
    for(int i = 0; i < sequence.size(); i++)
    {
        mp.push_back(sequence[i] * (i % 2 == 0 ? -1 : 1 ));
        pm.push_back(sequence[i] * (i % 2 == 0 ? 1 : -1 ));
    }
    
    vector<long long> dp1(sequence.size(), LLONG_MIN);
    vector<long long> dp2(sequence.size(), LLONG_MIN);
    dp1[0] = mp[0];
    dp2[0] = pm[0];
    answer = max(answer, dp1[0]);
    answer = max(answer, dp2[0]);
    
    for(int i = 1; i < sequence.size(); i++)
    {
        dp1[i] = (dp1[i-1] + mp[i]) > mp[i] ? (dp1[i-1] + mp[i]) : mp[i];
        dp2[i] = (dp2[i-1] + pm[i]) > pm[i] ? (dp2[i-1] + pm[i]) : pm[i];
        answer = max(answer, dp1[i]);
        answer = max(answer, dp2[i]);
    }
    
    return answer;
}
*/