class Solution {
public:
    vector<vector<int>> result;

    void DFS(vector<int>& candidates, int target, int curIndex, vector<int>& temp)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }

        for(int i = curIndex; i < candidates.size(); i++)
        {
            if(target < candidates[i]) break;
            
            temp.push_back(candidates[i]);
            DFS(candidates, target-candidates[i], i, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        DFS(candidates, target, 0, temp);

        return result;
    }
};