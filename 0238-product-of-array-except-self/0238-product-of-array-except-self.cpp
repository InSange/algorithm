class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 왼쪽 곱 - 현재 - 오른쪽 ㄱㅎㅂ -> 현재는 왼쪽 곱 * 오른쪽 곱
        int n = nums.size();

        vector<int> answer(n);

        answer[0] = 1;
        for(int i = 1; i < n; i++)
        {
            answer[i] = answer[i-1] * nums[i - 1];
        }

        int RightV = 1;
        for(int i = n-1; i >= 0; i--)
        {
            answer[i] = answer[i] * RightV;
            RightV *= nums[i];
        }

        return answer;
    }
};