class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, bool> checkNum;
        
        for(int val : target)
        {
            checkNum[val] = true;
        }
        
        for(int val : arr)
        {
            if(checkNum[val]) continue;
            return false;
        }
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < target.size(); i++)
        {
            if(target[i] != arr[i]) return false;
        }
        return true;
    }
};