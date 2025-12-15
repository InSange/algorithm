#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void turnClock(vector<int>& answer, vector<vector<int>>& graph, int x1, int y1, int x2, int y2)
{
    int minVal = 10001;
    int temp1 = graph[x1][y1], temp2 = 0;
    
    // y1 -> y2 ++ graph[x][y]
    for(int i = y1; i < y2; i++)
    {
        temp2 = graph[x1][i+1];
        graph[x1][i+1] = temp1;
        temp1 = temp2;
        minVal = min(minVal ,graph[x1][i+1]);
    }
    // x1 -> x2 ++
    for(int i = x1; i < x2; i++)
    {
        temp2 = graph[i+1][y2];
        graph[i + 1][y2] = temp1;
        temp1 = temp2;
        minVal = min(minVal ,graph[i+1][y2]);
    }
    // y2 -> y1 --
    for(int i = y2; i > y1; i--)
    {
        temp2 = graph[x2][i-1];
        graph[x2][i-1] = temp1;
        temp1 = temp2;
        minVal = min(minVal ,graph[x2][i-1]);
    }
    // x2 -> x1 --
    for(int i = x2; i > x1; i--)
    {
        temp2 = graph[i-1][y1];
        graph[i - 1][y1] = temp1;
        temp1 = temp2;
        minVal = min(minVal ,graph[i-1][y1]);
    }
    
    //graph[x1][y1] = temp1;
    minVal = min(minVal ,temp1);
    
    answer.push_back(minVal);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> graph(rows + 1, vector<int>(columns + 1, 0));
    
    int number = 1;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            graph[i][j] = number++;
            //cout << graph[i][j] << " ";
        }
        //cout << "\n";
    }
    
    for(const vector<int> query : queries)
    {
        turnClock(answer, graph, query[0], query[1], query[2], query[3]);
    }
    
    return answer;
}