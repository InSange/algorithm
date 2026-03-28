#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    
    int move = len - 1; 
    
    for (int i = 0; i < len; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int next_idx = i + 1;
        while (next_idx < len && name[next_idx] == 'A') {
            next_idx++;
        }
        
        move = min(move, i * 2 + (len - next_idx)); 
        move = min(move, (len - next_idx) * 2 + i); 
    }
    
    answer += move;
    
    return answer;
}