class Solution {
public:
    struct compare 
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if(a.first == b.first)
            {
                if(a.second < b.second) return true;
                else return false;
            }
            else if(a.first > b.first) return true;
            else return false;
        }
    };
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> numCnts;
        
        numCnts.assign(201, 0);
        
        for(int num : nums)
        {
            numCnts[num+100]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // first:cnt, first:val
        
        vector<int> ans;
        
        for(int i = 0; i < 201; i++)
        {
            if(numCnts[i])
            {
                pq.push({numCnts[i], i-100});
            }
        }
        
        while(!pq.empty())
        {
            int cnt = pq.top().first;
            int val = pq.top().second;
            
            pq.pop();
            
            for(int i = 0; i < cnt; i++)
            {
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};