class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSum = 0, left = 0, right = height.size() - 1;

        while(left < right)
        {
            if(height[left] <= height[right])
            {
                maxSum = max(maxSum, height[left] * (right-left));
                left++;
            }
            else
            {
                maxSum = max(maxSum, height[right] * (right-left));
                right--;
            }
            
        }

        return maxSum;
    }
};