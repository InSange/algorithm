#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, set<string>> reportMap;
    unordered_map<string, int> reportCnt;
    
    for(auto& data : report)
    {
        string s1 = "";
        string s2 = "";
        bool isTrigger = true;
        for(char& c : data)
        {
            if(isTrigger)
            {
                if(c == ' ')
                {
                    isTrigger = false;
                    continue;
                }
                s1 += c;
            }
            else
            {
                s2 += c;
            }
        }
        
        auto iter = find(reportMap[s1].begin(), reportMap[s1].end(), s2);
        if(iter == reportMap[s1].end()) reportCnt[s2]++;
        reportMap[s1].insert(s2);
    }
    
    vector<int> answer;
    
    for(auto& id : id_list)
    {
        int cnt = 0;
        for(auto& r : reportMap[id])
        {
            if(reportCnt[r] >= k) cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}