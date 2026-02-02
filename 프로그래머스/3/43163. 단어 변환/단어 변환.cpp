#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(string begin, string& target, vector<string>& words, vector<bool>& visited, int& answer, int cnt)
{
    if(target == begin)
    {
        if(answer == 0 || answer > cnt) answer = cnt;
        return;
    }
    
    for(int i = 0; i < words.size(); i++)
    {
        if(visited[i]) continue;
        
        int sameCnt = 0;
        for(int j = 0; j < words[i].length(); j++)
        {
            if(begin[j] == words[i][j]) sameCnt++;
        }
        
        if(sameCnt == (target.length() - 1))
        {
            visited[i] = true;
            dfs(words[i], target, words, visited, answer, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    auto it = find(words.begin(), words.end(), target);
    if(it == words.end()) return 0;
    
    vector<bool> visited(words.size(), false);
    
    dfs(begin, target, words, visited, answer, 0);
    
    return answer;
}