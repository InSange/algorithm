class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        sort(details.begin(), details.end(), [](const string& a, const string& b)
             {
                 if(a[11] == b[11]) return a[12] > b[12];
                 return a[11] > b[11];
             });
        
        for(string detail : details)
        {
            cout << detail << "\n";
            if(detail[11] > '6')
            {
                ans++;
                continue;
            }
            if(detail[11] == '6' && detail[12] > '0')
            {
                ans++;
                continue;
            }
            else break;
        }
        
        return ans;
    }
};