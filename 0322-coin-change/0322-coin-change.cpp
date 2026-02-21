class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<bool> visited(amount + 1, false);
        visited[amount] = true;

        queue<pair<int, int>> q;
        q.push({amount, 0});

        while (!q.empty()) {
            int cur = q.front().first;
            int count = q.front().second;
            q.pop();
            
            for (int coin : coins) {
                int next_amount = cur - coin;

                if (next_amount == 0) return count + 1;

                if (next_amount > 0 && !visited[next_amount]) {
                    visited[next_amount] = true;
                    q.push({next_amount, count + 1});
                }
            }
        }

        return -1;
    }
};