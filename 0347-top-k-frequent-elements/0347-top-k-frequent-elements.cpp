class Solution {
public:
    bool compare(pair<int, int>a, pair<int, int>b)
    {
        if(a.second > b.second) return false;
        return true;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        for(auto v : nums)
        {
            um[v]++;
        }
        
        for(pair<int, int> v : um)
        {
            pq.push({v.second, v.first});
        }
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};