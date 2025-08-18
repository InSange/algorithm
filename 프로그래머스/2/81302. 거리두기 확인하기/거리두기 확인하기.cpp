#include <string>
#include <vector>
#include <iostream>

using namespace std;

// P에서 O를 만나면 -> O 상하좌우에 P가 있는지 확인
// P에서 P를 만나면 거리두기 x
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int row = places[0].size();
    int col = places[0][0].size();
    
    for(auto place : places)
    {
        bool isContinue = false;
        for(int i = 0; i < row; i++)
        {
            if(isContinue) break;
            for(int j = 0; j < col; j++)
            {
                if(isContinue) break;
                if(place[i][j] == 'O' || place[i][j] == 'X') continue;
                // 즉 place[i][j] 가 P일 때
                for(int k = 0; k < 4; k++)
                {
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if(nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
                    if(place[ny][nx] == 'P')
                    {
                        cout << i << ", " << j << ", " << ny << ", " << nx << "\n";
                        isContinue = true;
                        break;
                    }
                    else if(place[ny][nx] == 'O')
                    {
                        for(int l = 0; l < 4; l++)
                        {
                            int nnx = nx + dx[l];
                            int nny = ny + dy[l];
                            if(nnx == j && nny == i) continue;
                            if(nnx < 0 || nnx > 4 || nny < 0 || nny > 4) continue;
                            if(place[nny][nnx] == 'P')
                            {
                                cout << i << ", " << j << ", " << nny << ", " << nnx << "\n";
                                isContinue = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(isContinue) answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}
