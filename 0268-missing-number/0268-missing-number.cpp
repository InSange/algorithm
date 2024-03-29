class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answer = nums.size()*(nums.size()+1)/2;
        
        for(auto n : nums)
        {
            answer -= n;
        }
        
        return answer;
    }
};