class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canJump = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(canJump < i) return false; 
            canJump = max(canJump, i + nums[i]);
            if(canJump == nums.size()) break;
        }

        return true;
    }
};