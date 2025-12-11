#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

// 이진 탐색
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1;
    int right = 200000000;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        int skip = 0;
        
        for(int stone : stones)
        {
            if(stone < mid)
            {
                skip++;
                if(skip >= k) break;
            }
            else
            {
                skip = 0;
            }
        }
        
        if(skip >= k)
        {
            right = mid - 1;
        }
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}

// 방법 2, 현재 징검다리가 0이 되면 다음 징검다리 돌한테 너 한칸 뛰어야해! 라고 알려주고(요구 점프 값 증가), 그 값이 k가 되면 끝. 효율성 13번에서 걸림.
/*
int solution(vector<int> stones, int k) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ssize = stones.size();
    
    vector<int> needJump; // 점프 요구치
    needJump.assign(ssize+1, 0);
    
    for(int i = 0; i < ssize; i++)
    {
        pq.push({stones[i], i + 1});
    }
    
    int niniz = 0;
    
    while(1)
    {
        pii curStones = pq.top();
        pq.pop();
        
        while(curStones.first > niniz) niniz++; // 가장 적은 수의 징검다리를 건널 수 있는 니니즈의 수
        
        needJump[curStones.second] = needJump[curStones.second - 1] + 1;

        int cntK = needJump[curStones.second];
        while(curStones.second <= ssize && needJump[curStones.second + 1] > 0)
        {
            needJump[curStones.second+1] = needJump[curStones.second] + 1;
            cntK = needJump[curStones.second+1];
            curStones.second++;
        }
        
        if(cntK >= k)break;
    }
    
    return niniz;
}
*/
// 방법 1 , 0이되면 양쪽을 탐색해서 k를 넘어가는지 확인.
/*
int solution(vector<int> stones, int k) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ssize = stones.size();
    
    for(int i = 0; i < ssize; i++)
    {
        pq.push({stones[i], i});
        //cout << pq.top().first << ", " << pq.top().second << "\n";
    }
    
    int niniz = 0;
    
    while(1)
    {
        pii curStones = pq.top();
        pq.pop();
        
        while(curStones.first > niniz) niniz++; // 가장 적은 수의 징검다리를 건널 수 있는 니니즈의 수
        stones[curStones.second] -= niniz; // 해당 징검다리를 0으로 만듬.
        
        int check = 1;
        int left = curStones.second, right = curStones.second;
        while(left >= 0 && stones[--left] == 0) check++;
        while(right < ssize && stones[++right] == 0) check++;
        
        if(check >= k) break;
    }
    
    return niniz;
}
*/