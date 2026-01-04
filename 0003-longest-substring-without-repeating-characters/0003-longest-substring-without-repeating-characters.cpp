class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, answer = 0;
        unordered_map<char, int> um;

        while(right < s.size())
        {
            int cur = right;
            right++;
            um[s[cur]]++;
            if(um[s[cur]] > 1)
            {
                while(left < right)
                {
                    um[s[left++]]--;
                    if(um[s[cur]] == 1) break;
                }
            }

            answer = max(answer, right-left);
        }

        return answer;
    }
};