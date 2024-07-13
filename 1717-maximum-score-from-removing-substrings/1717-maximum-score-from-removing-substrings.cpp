class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        
        stack<char> st_big;
        stack<char> st_small;
        
        string big = "ba";
        string small = "ab";
        
        if(x > y)
        {
            swap(x, y);
            big = "ab";
            small = "ba";
        }

        for(char c : s)
        {
            if(c == big[1] && !st_big.empty() && st_big.top() == big[0])
            {
                score += y;
                st_big.pop();
                continue;
            }
            
            st_big.push(c);
        }
        
        while(!st_big.empty())
        {
            char c = st_big.top();
            st_big.pop();
            
            if(c == small[0] && !st_small.empty() && st_small.top() == small[1])
            {
                score += x;
                st_small.pop();
                continue;
            }
            
            st_small.push(c);
        }
        
        return score;
    }
};