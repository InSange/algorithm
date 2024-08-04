class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0, mod = pow(10, 9)+7, i;
        
        for(i = 0; i < n; i++) pq.push({nums[i], i});
        
        i = 1;
        while(i <= right)
        {
            pair<int, int> cur = pq.top();
            pq.pop();
            
            if(i >= left) ans = (ans + cur.first) % mod;
            if(cur.second < n-1)
            {
                cur.first += nums[++cur.second];
                pq.push(cur);
            }
            i++;
        }
        
        return ans;
    }
};