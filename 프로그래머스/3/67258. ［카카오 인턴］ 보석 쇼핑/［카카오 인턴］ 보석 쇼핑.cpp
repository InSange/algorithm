#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0), answer.push_back(gems.size());
    
    unordered_set<string> kinds;
    kinds.insert(gems.begin(), gems.end());
    
    unordered_map<string, int> gemCnt;
    unordered_set<string> curGems;
    int left = 0, right = 0;
    
    while(right < gems.size() && left <= right)
    {
        gemCnt[gems[right]]++;
        if(gemCnt[gems[right]] == 1) curGems.insert(gems[right]);
        
        while(curGems.size() == kinds.size())
        {
            if((answer[1] - answer[0]) > (right - left))
            {
                answer[0] = left+1;
                answer[1] = right+1;    
            }

            gemCnt[gems[left]]--;
            if(gemCnt[gems[left]] == 0) // 음수로 될 일은 없음.
            {
                curGems.erase(gems[left]);
            }
            left++;
        }
        
        right++;
    }
    
    return answer;
}