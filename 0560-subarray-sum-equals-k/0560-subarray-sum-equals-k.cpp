class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0, sum = 0;
        unordered_map<int, int> um;
        
        for(int i = 0; i < nums.size(); i++)
        {
            um[sum]++;
            sum += nums[i];

            if(um[sum-k]) answer += um[sum-k];
        }

        return answer;
    }
};