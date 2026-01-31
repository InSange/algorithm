#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parent(n);
    for(int i = 0; i < n; i++) parent[i] = i;
    
    function<int(int)> getParent = [&](int x) -> int {
        if(parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    };
    
    auto unionFind = [&](int a, int b) -> bool {
        a = getParent(a);
        b = getParent(b);
        
        if(a == b) return false;
        
        if(a < b) parent[a] = b;
        else parent[b] = a;
        
        return true;
    };
    
    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b){
        return a[2] < b[2];
    });
    
    for(const auto& cost : costs)
    {
        if(unionFind(cost[0], cost[1]))
        {
            answer += cost[2];
        }
    }
    
    return answer;
}