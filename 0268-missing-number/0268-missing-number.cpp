class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        for(auto n : nums)
        {
            if(index == n) index++;
            else break;
        }
        
        return index;
    }
};