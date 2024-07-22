class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        
        int i = 0;
        priority_queue<pair<int, int>> pq;
        
        for(int height : heights)
        {
            pq.push({height, i++});
        }
        
        while(!pq.empty())
        {
            ans.push_back(names[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};