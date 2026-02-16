class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0, count = 0;

        if(height.size() < 2) return count;

        for(int i = 1; i < height.size(); i++)
        {
            if(height[start] <= height[i])
            {
                int value = height[start++];
                while(start<i)
                {
                    count += value - height[start++];
                }
            }
        }

        int top = height.size() - 1;

        for(int i = top-1; i >= start; i--)
        {
            if(height[top] <= height[i])
            {
                int value = height[top--];
                while(top>i)
                {
                    count += value - height[top--];
                }
            }
        }


        return count;
    }
};