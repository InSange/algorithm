#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int index = 0;

bool compare(const vector<int>& a, const vector<int>& b)
{
    if(a[index] == b[index]) return a[0] > b[0];
    else return a[index] < b[index];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<int> S_i;
    
    index = col-1;
    sort(data.begin(), data.end(), compare);
    
    for(int i = row_begin; i <= row_end; i++)
    {
        int sum = 0;
        for(int& v : data[i-1])
        {
            sum += (v%i);
        }
        S_i.push_back(sum);
    }
    
    for(int& i : S_i)
    {
        answer ^= i;
    }
    
    return answer;
}