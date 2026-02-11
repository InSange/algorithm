#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](const auto& a, const auto& b){
        return a[1] < b[1];
    });
    int answer = 1, end = routes[0][1];
    
    for(int i = 1; i < routes.size(); i++)
    {
        if(end < routes[i][0])
        {
            answer++;
            end = routes[i][1];
        }
    }
    
    
    return answer;
}