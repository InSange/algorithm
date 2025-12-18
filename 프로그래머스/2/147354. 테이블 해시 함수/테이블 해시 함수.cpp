#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    sort(data.begin(), data.end(),[col] (const vector<int>& a, const vector<int>& b) {
        int idx = col - 1;
        if(a[idx] == b[idx]) return a[0] > b[0];
        return a[idx] < b[idx];
    });
    
    for(int i = row_begin; i <= row_end; i++)
    {
        int sum = 0;
        int row_idx = i - 1;
        
        for(int& v : data[row_idx])
        {
            sum += (v%i);
        }
        answer ^= sum;
    }
    
    return answer;
}