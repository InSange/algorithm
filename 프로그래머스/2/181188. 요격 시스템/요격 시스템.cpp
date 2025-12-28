#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
using pii = pair<int,int>;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end());
    int se = targets[0][0], ee = targets[0][1]; // se 시작은 가장 짧은 s를 찾고 끝은 e부분이 가장 작은 부분을 찾아서 asnwer 값을 갱신하기.
    
    for(int i = 1; i < targets.size(); i++)
    {
        if(ee <= targets[i][0]) //그다음 타겟의 s가 현재의 e보다 크거나 같을 경우
        {
            answer++;
            se = targets[i][0];
            ee = targets[i][1];
        }
        else if(ee <= targets[i][1])// ee 범위가 넘어갈 경우.
        {
            se = targets[i][0];
        }
        else if(ee > targets[i][1])
        {
            se = targets[i][0];
            ee = targets[i][1];
        }
    }
    
    return answer;
}