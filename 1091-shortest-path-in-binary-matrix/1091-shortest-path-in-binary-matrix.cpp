
class Solution {
public:
    using pii = pair<int, int>;
    
    int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1 };

    bool OutOfBounds(int y, int x, int n) {
        return (y >= 0 && y < n && x >= 0 && x < n);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        queue<pii> q;
        q.push({0, 0});
        visited[0][0] = 1;

        while(!q.empty())
        {
            int curY = q.front().first, curX = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++)
            {
                int nextY = curY + dy[i], nextX = curX + dx[i];

                if(!OutOfBounds(nextY, nextX, n)) continue;
                if(grid[nextY][nextX]) continue;
                if(visited[nextY][nextX]) continue; // 이미 방문한 곳.

                visited[nextY][nextX] = visited[curY][curX] + 1;
                q.push({nextY, nextX});
            }
        }

        return visited[n-1][n-1] ? visited[n-1][n-1] : -1 ;
    }
};