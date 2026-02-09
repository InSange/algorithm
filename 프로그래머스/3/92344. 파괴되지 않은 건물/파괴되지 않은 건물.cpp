#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int answer = 0;
    int row = board.size(), col = board[0].size();
    
    vector<vector<int>> temp(row+1, vector<int>(col+1, 0));
    
    for(auto& skill : skills)
    {
        int type = skill[0], r1 = skill[1], c1 = skill[2], r2 = skill[3], c2 = skill[4], degree = skill[5];
        
        int val = (type == 1 ? -degree : degree);
        temp[r1][c1] += val;
        temp[r1][c2+1] -= val;
        temp[r2+1][c1] -= val;
        temp[r2+1][c2+1] += val;
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            temp[i + 1][j] += temp[i][j];
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            temp[i][j + 1] += temp[i][j];
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            board[i][j] += temp[i][j];
            if(board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}