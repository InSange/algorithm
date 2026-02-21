class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int answer = 0;
        unordered_map<int, int> um;
        um[amount] = 0;

        queue<int> q;

        q.push(amount);

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for(auto& coin : coins)
            {
                int next = cur - coin;

                if(next>= 0)
                {
                    if(um[next]) continue;
                    else
                    {
                        um[next] = um[cur]+1;
                    }

                    q.push(next);
                }   
            }
        }

        return um[0] ? um[0] : -1;
    }
};