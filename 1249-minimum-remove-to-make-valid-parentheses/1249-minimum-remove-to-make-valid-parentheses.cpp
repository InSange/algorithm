class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string answer = "";
        stack<int> st;
        vector<char> v;
        int len = 0;
        
        for(auto c : s)
        {
            v.push_back(c);
            if(c == '(') st.push(len);
            else if(c == ')')
            {
                if(st.empty()) v[len] = '-';
                else st.pop();
            }
            len++;
        }
        
        while(!st.empty())
        {
            int index = st.top();
            st.pop();
            v[index] = '-';
        }
        
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == '-') continue;
            answer += v[i];
        }
        
        return answer;
    }
};