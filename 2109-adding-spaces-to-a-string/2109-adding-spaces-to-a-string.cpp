class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int cur = 0;
        
        for(const auto& len : spaces)
        {
            ans += s.substr(cur, len-cur) + ' ';
            cout << len << " : " << s.substr(cur, len-cur) << "\n";
            cur = len;
        }
        
        ans += s.substr(cur);
        
        return ans;
    }
};