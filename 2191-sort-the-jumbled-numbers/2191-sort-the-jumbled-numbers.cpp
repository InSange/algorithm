class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // first : after value, second : previous value
        
        for(int i = 0; i < nums.size(); i++)
        {
            string cur = to_string(nums[i]);
            
            for(int i = 0; i < cur.length(); i++)
            {
                int val = cur[i]-'0';
                cur[i] = mapping[val] + '0';
            }
            
            pq.push({stoi(cur), i});
        }
        
        while(!pq.empty())
        {
            cout << pq.top().first ;
            ans.push_back(nums[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};