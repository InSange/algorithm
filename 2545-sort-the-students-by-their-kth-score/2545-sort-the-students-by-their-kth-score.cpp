class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        int rowNum = score.size();
        int colNum = score[0].size();
        
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < rowNum; i++)
        {
            pq.push({score[i][k], i});
        }
        
        while(!pq.empty())
        {
            int curRow = pq.top().second;
            pq.pop();
            
            ans.push_back(score[curRow]);
        }
        
        return ans;
    }
};