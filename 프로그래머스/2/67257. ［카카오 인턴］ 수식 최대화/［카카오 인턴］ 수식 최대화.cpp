#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> opsArray; // 연산자들 담을 배열
vector<long long> numArray; // 피연산자들 담을 배열

bool visited[3]; // 순열을 위한 방문 배열
char ops[3] = {'+', '-', '*'}; // 기본 연산자들
long long maxVal = 0;

void calc(vector<char>& opsPer)
{
    vector<char> copyOps = opsArray;
    vector<long long> copyNum = numArray;
    
    for(const char& op : opsPer)
    {
        for(int i = 0; i < copyOps.size(); i++)
        {
            if(op != copyOps[i]) continue;
            if(op == '+') copyNum[i] = copyNum[i] + copyNum[i+1];
            else if(op == '-') copyNum[i] = copyNum[i] - copyNum[i+1];
            else copyNum[i] = copyNum[i] * copyNum[i+1];
            
            copyNum.erase(copyNum.begin() + i + 1);
            copyOps.erase(copyOps.begin() + i);
            i--;
        }
    }

    maxVal = max(maxVal, abs(copyNum[0])); 
}

void dfs(vector<char>& opsPer, int cnt)
{
    if(cnt == 3)
    { // 3개일 때 값 계산하기
        calc(opsPer);
        return;
    }
    
    for(int i = 0; i < 3; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        opsPer.push_back(ops[i]);
        dfs(opsPer, cnt+1);
        opsPer.pop_back();
        visited[i] = false;
    }
}

// +, -, * 순열 만들고 계산하기.
long long solution(string expression) {
    long long answer = 0;
    string s = "";
    
    for(const char& c : expression)
    {
        if(c == '+' || c == '-' || c == '*')
        {
            opsArray.push_back(c);
            numArray.push_back(stoll(s));
            s = "";
        }
        else
        {
            s += c;
        }
    }
    
    vector<char> opsPer;
    numArray.push_back(stoll(s));
    dfs(opsPer, 0);
    
    return maxVal;
}