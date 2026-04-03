#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    // problems의 원소는 
    // [필요한 알고력, 필요한 코딩력, 증가하는 알고력, 증가하는 코딩력, 시간]
    int answer = 0;
    int maxAlp = alp;
    int maxCop = cop;
    
    for(int i = 0; i < problems.size(); i++)
    {
        maxAlp = max(maxAlp, problems[i][0]);
        maxCop = max(maxCop, problems[i][1]);
    }
    
    vector<vector<int>> dp(maxAlp + 2, vector<int>(maxCop + 2, 1e9));
    dp[alp][cop] = 0;
    
    for(int i = alp; i <= maxAlp; i++) {
        for(int j = cop; j <= maxCop; j++) {
            
            // 1. 알고리즘 공부 1시간
            if (i + 1 <= maxAlp) 
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            
            // 2. 코딩 공부 1시간
            if (j + 1 <= maxCop) 
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            
            // 3. 문제 풀기 
            for(auto& p : problems) {
                int req_alp = p[0];
                int req_cop = p[1];
                int rwd_alp = p[2];
                int rwd_cop = p[3];
                int cost = p[4];
                
                if (i >= req_alp && j >= req_cop) {
                    int next_alp = min(maxAlp, i + rwd_alp);
                    int next_cop = min(maxCop, j + rwd_cop);
                    
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost);
                }
            }
        }
    }
    
    return dp[maxAlp][maxCop];
}