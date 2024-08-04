class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        for(int i = 0; i < n; i++)
        {
            long long sum = nums[i];
            for(int j = i+1; j < n; j++)
            {
                sum += nums[j];
                nums.push_back(sum);
            }
        }
        
        sort(nums.begin(), nums.end());
        
        const int mod = pow(10, 9) + 7;
        long long ans = 0;

        for(int i = left; i <= right; i++)
        {
            ans = (ans + nums[i-1]) % mod;
        }
        
        return ans;
    }
};