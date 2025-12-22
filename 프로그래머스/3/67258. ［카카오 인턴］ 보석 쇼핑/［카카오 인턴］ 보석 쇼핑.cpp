#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 0};
    unordered_map<string, int> m;
    set<string> s1;
    int start = 0, end = 0, gsize = gems.size(), ssize = 0, len = 100001;
    
    for(int i = 0; i < gsize; i++)
    {
        s1.insert(gems[i]);
    }
    
    while(start <= end && start < gsize)
    {
        if(ssize == s1.size() && (end-start)+1 < len)
        {
            len = end-start+1;
            answer[0] = start+1;
            answer[1] = end;
        }

        if(ssize < s1.size() && end < gsize)
        {
            m[gems[end]]++;
            if(m[gems[end]] == 1) ssize++;
            end++;
        }
        else 
        {
            m[gems[start]]--;
            if(m[gems[start]] == 0)
            {
                ssize--;
            }
            start++;
        }
    }
    
    return answer;
}