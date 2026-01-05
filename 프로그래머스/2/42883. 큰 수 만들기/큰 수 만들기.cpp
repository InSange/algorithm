#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> st;
    
    for(int i = 0; i < number.size(); i++)
    {
            while(!st.empty() && st.top() < number[i] && k > 0)
            {
                st.pop();
                k--;
            }
        
        st.push(number[i]);
    }
    
    while(!st.empty()) 
    {
        if(k > 0) k--;
        else answer += st.top();
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}