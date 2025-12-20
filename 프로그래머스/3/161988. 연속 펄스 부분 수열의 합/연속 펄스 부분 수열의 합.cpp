#include <string>
#include <vector>
#include <limits.h>

using namespace std;

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