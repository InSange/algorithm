#include <string>
#include <vector>

using namespace std;

bool installed[105][105][2];
int N;

bool check(int x, int y, int type) {
    // 기둥(0)인 경우
    if (type == 0) {
        // 바닥이거나
        if (y == 0) return true;
        // 바로 아래 기둥이 있거나
        if (installed[x][y - 1][0]) return true;
        // 보 위에 있거나 (내 위치의 보 OR 왼쪽 끝 보)
        if (installed[x][y][1] || (x > 0 && installed[x - 1][y][1])) return true;
    }
    // 보(1)인 경우
    else {
        // 한쪽 끝이 기둥 위에 있거나 (왼쪽 아래 기둥 OR 오른쪽 아래 기둥)
        if (installed[x][y - 1][0] || installed[x + 1][y - 1][0]) return true;
        // 양쪽이 보로 연결되어 있거나 (왼쪽 보 AND 오른쪽 보)
        if (x > 0 && installed[x - 1][y][1] && installed[x + 1][y][1]) return true;
    }
    return false;
}

bool isValid() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (installed[i][j][0] && !check(i, j, 0)) return false;
            if (installed[i][j][1] && !check(i, j, 1)) return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
   for (auto& frame : build_frame) {
        int x = frame[0], y = frame[1], type = frame[2], action = frame[3];

        if (action == 1) { 
            installed[x][y][type] = true; 
            if (!isValid()) { 
                installed[x][y][type] = false; 
            }
        }
        else { 
            installed[x][y][type] = false;
            if (!isValid()) {
                installed[x][y][type] = true;
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (installed[x][y][0]) answer.push_back({x, y, 0});
            if (installed[x][y][1]) answer.push_back({x, y, 1});
        }
    }
    
    return answer;
}