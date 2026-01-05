#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for(int i = 0; i < number.size(); i++)
    {
        while(!answer.empty() && answer.back() < number[i] && k > 0)
        {
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    
    if(k > 0) answer.resize(answer.length() - k);
    
    return answer;
}