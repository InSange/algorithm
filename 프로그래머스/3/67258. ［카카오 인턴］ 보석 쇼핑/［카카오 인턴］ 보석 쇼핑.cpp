#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, -1);
    set<string> gemSet;
    unordered_map<string, int> gemCnt;
    
    for(const string& gem : gems) gemSet.insert(gem);
    for(const string& gem : gemSet) gemCnt[gem] = 0;
    cout << gemSet.size() << gemCnt.size() << "\n";
    
    int start = 0;
    set<string> curSet;
    
    for(int end = 0; end < gems.size(); end++)
    {      
        // 보석 추가
        curSet.insert(gems[end]);
        gemCnt[gems[end]]++;
        
        if(curSet.size() != gemSet.size()) continue;
        // start의 보석이 2개 이상일 경우 start를 업데이트하기
        while(gemCnt[gems[start]] > 1) 
        {
            gemCnt[gems[start]]--;
            start++;
        }
        
        // answer 값이 업데이트 안되었을 때(-1) or 이전의 answer 구간 길이보다 현재가 짧을 때
        if(answer[0] == -1 || (answer[1] - answer[0]) > (end - start))
        {
            answer[0] = start + 1;
            answer[1] = end + 1;
        }
    }
    
    
    return answer;
}