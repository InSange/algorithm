class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        int rowNum = score.size();
        int colNum = score[0].size();
        
        ans.assign(rowNum, vector<int>(colNum, 0));
        
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < rowNum; i++)
        {
            pq.push({score[i][k], i});
        }
        
        int rowIndex = 0;
        while(!pq.empty())
        {
            int curRow = pq.top().second;
            pq.pop();
            
            for(int i = 0; i < colNum; i++)
            {
                ans[rowIndex][i] = score[curRow][i];
            }
            
            rowIndex++;
        }
        
        return ans;
    }
};