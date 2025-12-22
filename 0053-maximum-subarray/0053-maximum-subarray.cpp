class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minSum = 0, sum = 0, answer = nums[0];   

        for(const int& num : nums)
        {
            sum += num;
            answer = max(answer, sum - minSum);
            minSum = min(minSum, sum);
        }

        return answer;
    }
};