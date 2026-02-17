class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> um;

        for(char& c : t)
        {
            um[c]++;
        }

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        int count = t.length();
        
        while(right < s.length())
        {
            if(um[s[right]] > 0) 
            {
                count--;
            }

            um[s[right]]--;
            right++;

            while(count == 0)
            {
                if(right - left < minLen)
                {
                    minLen = right - left;
                    startIndex = left;
                }

                if(um[s[left]] == 0)
                {
                    count++;
                }

                um[s[left]]++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};