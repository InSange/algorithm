class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0, sum = 0;
        unordered_map<int, int> um;
        
        um[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if(um[sum-k]) answer += um[sum-k];
            um[sum]++;
        }

        return answer;
    }
};