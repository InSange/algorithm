class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        for(int i = 0; i < n; i++)
        {
            int sum = nums[i];
            for(int j = i+1; j < n; j++)
            {
                sum += nums[j];
                nums.push_back(sum);
            }
        }
        
        sort(nums.begin(), nums.end());
        
        int mod = pow(10, 9) + 7;
        int ans = 0;

        for(int i = left; i <= right; i++)
        {
            ans = (nums[i-1]+ans) % mod;
        }
        
        return ans;
    }
};