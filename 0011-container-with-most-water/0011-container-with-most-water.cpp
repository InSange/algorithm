class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSum = 0, left = 0, right = height.size() - 1;

        while(left < right)
        {
            int h = min(height[left], height[right]);
            maxSum = max(maxSum, h * (right - left));

            while (left < right && height[left] <= h) {
                left++;
            }
            while (left < right && height[right] <= h) {
                right--;
            }
        }

        return maxSum;
    }
};