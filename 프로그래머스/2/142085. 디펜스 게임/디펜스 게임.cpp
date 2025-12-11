#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// enemy 값을 더하고 queue에 저장.
// 만약 더한 값이 n보다 크면 queue에서 pop해서 k소비
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int cost = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    
    for(int e : enemy)
    {
        cost += e;
        pq.push(e);
        while(n < cost && k)
        {
            cost -= pq.top();
            pq.pop();
            k--;
        }
        
        if(cost > n) break;
        answer++;
    }
    
    return answer;
}