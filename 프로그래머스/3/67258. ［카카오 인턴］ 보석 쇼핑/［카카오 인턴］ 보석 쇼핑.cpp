#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 0};
    set<string> gemSet(gems.begin(), gems.end());
    int setCnt = gemSet.size();
    
    unordered_map<string, int> m;
    int start = 0, minLen = 100001;
    
    for(int end = 0; end < gems.size(); end++)
    {
        m[gems[end]]++;
        
        if(m.size() == setCnt)
        {
            while(m[gems[start]] > 1)
            {
                m[gems[start]]--;
                start++;
            }
            
            if(end - start < minLen)
            {
                minLen = end-start;
                answer[0] = start+1;
                answer[1] = end+1;
            }
        }
    }
    
    return answer;
}