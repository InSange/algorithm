#include <string>
#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<vector<int>>& v)
{
    int m = v.size();
    
    vector<vector<int>> temp(m, vector<int>(m));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            temp[i][j] = v[m-j-1][i];
        }
    }
    
    v = temp;
}

bool check(vector<vector<int>> bg, vector<vector<int>>& k, int offset, int lockSize, int row, int col) {
    int kSize = k.size();
    
    for(int i = 0; i < kSize; i++)
    {
        for(int j = 0; j < kSize; j++)
        {
            bg[row + i][col + j] += k[i][j];
        }
    }
    
    for(int i = 0; i < lockSize; i++) {
        for(int j = 0; j < lockSize; j++) {
            // 중앙 자물쇠 영역 (offset부터 시작)
            if(bg[offset + i][offset + j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int lockSize = lock.size(), keySize = key.size();
    int mapSize = lockSize + (2 * (keySize -1));
    
    vector<vector<int>> map(mapSize, vector<int>(mapSize, 0));
    
    for(int i = 0; i < lockSize; i++)
    {
        for(int j = 0; j < lockSize; j++)
        {
            map[i + keySize - 1][j + keySize - 1] = lock[i][j];
        }
    }
    
    for(int k = 0; k < 4; k++)
    {
        for(int i = 0; i <= mapSize - keySize; i++)
        {
            for(int j = 0; j <= mapSize - keySize; j++)
            {
                if(check(map, key, keySize - 1, lockSize, i, j)) return true;
            }
            cout << "\n";
        }
        rotate(key);
    }
    
    return false;
}