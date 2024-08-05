class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        string ans = "";
        
        for(string& str : arr)
        {
            m[str]++;
        }
        
        vector<string> v;
        for(string& str : arr)
        {
            if(m[str] == 1) v.push_back(str);
        }
        
        if(k > v.size()) return "";
        return v[k-1];
    }
};