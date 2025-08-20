#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    int arr[100000][4];
    
    for(int i = 0; i < land.size()-1; i++)
    {
        pair<int,int> first = {0, 0};
        pair<int,int> second = {0, 0};
        
        for(int j = 0; j < 4; j++)
        {
            if(land[i][j] >= first.first)
            {
                second = first;
                first = {land[i][j], j};
            }
            else if(land[i][j] >= second.first)
            {
                second = {land[i][j], j};
            }
        }
        for(int j = 0; j < 4; j++)
        {
            if(first.second == j)
            {
                land[i+1][j] += second.first;
            }
            else
            {
                land[i+1][j] += first.first;
            }
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(land[land.size()-1][i] >= answer) answer = land[land.size()-1][i];
    }


    return answer;
}