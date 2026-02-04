#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
// +, -, /, *, n*10+n
int solution(int N, int number) {
    int answer = 0;
    
    vector<unordered_set<int>> dp(9);
    
    for(int i = 1; i < 9; i++) // N을 몇개 사용했는가
    {
        int init = N;
        for(int j = 1; j < i; j++)
        {
            init = init * 10 + N;
        }
        
        dp[i].insert(init);
        
        for(int j = 1; j < i; j++)
        {
            for(int k = 1; k < i; k++)
            {
                if(j + k != i) continue;
                
                for(const int& a : dp[j])
                {
                    for(const int& b : dp[k])
                    {
                        dp[i].insert(a + b);
                        dp[i].insert(a * b);
                        if(a - b > 0) dp[i].insert(a - b);
                        if(b != 0) dp[i].insert(a/b);
                    }
                }
            }
        }
        
        if(dp[i].count(number)) return i;
    }
    
    return -1;
}