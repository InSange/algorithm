#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    if(n == 1) return sticker[0];
    
    int v1 = sticker[0], v2 = sticker[0]; // sticker의 0번째 즉, 첫번째 스티커를 뜯었을 때
    
    for(int i = 2; i < n-1; i++) // n-1번째 즉, 마지막의 스티커는 첫번째 스티커를 뜯었기 때문에 사용 X
    {
        int cur = max(v1 + sticker[i], v2);
        
        v1 = v2;
        v2 = cur;
    }
    
    answer = v2;
    
    v1 = 0, v2 = sticker[1]; // 두번째 스티커를 뜯었을 때
    for(int i = 2; i < n; i++)
    {
        int cur = max(v1 + sticker[i], v2);
        
        v1 = v2;
        v2 = cur;
    }
    
    return max(answer, v2);
}