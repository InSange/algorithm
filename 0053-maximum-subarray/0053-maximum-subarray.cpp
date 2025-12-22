class Solution {
public:
    int maxSubArray(vector<int>& nums) {
// dp[i-1] 역할을 하는 변수
        int prev_max = nums[0];
        int answer = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            // 점화식: max(나부터 새로 시작, 이전까지의 합 + 나)
            // dp[i] = max(nums[i], dp[i-1] + nums[i])
            int cur_max = max(nums[i], prev_max + nums[i]);
            
            answer = max(answer, cur_max);
            prev_max = cur_max; // 다음 턴을 위해 갱신
        }

        return answer;
    }
};