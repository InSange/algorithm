class Solution {
public:
    bool OutBounds(int y, int x, int row, int col)
    {
        return y < 0 || x < 0 || y >= row || x >= col;
    }  

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        int dy[4] = {0, 0, -1, 1};
        int dx[4] = {1, -1, 0, 0};

        vector<vector<int>> visited(row, vector<int>(col, 1e9));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // 0 : 피로도, 1 : y, 2 : x
        visited[0][0] = 0;

        while(!pq.empty())
        {
            int cost = pq.top()[0], curY = pq.top()[1], curX = pq.top()[2];
            pq.pop();
            if(curY == row -1 && curX == col -1) return cost;

            for(int i = 0; i < 4; i++)
            {
                int nextY = curY + dy[i], nextX = curX + dx[i];
                if(OutBounds(nextY, nextX, row, col)) continue;

                int diff = abs(heights[nextY][nextX] - heights[curY][curX]);
                if(visited[nextY][nextX] <= diff) continue;

                int nextCost = max(cost, diff);
                if(nextCost >= visited[nextY][nextX]) continue;

                visited[nextY][nextX] = nextCost;
                pq.push({nextCost, nextY, nextX});
            }
        }

        return visited[row-1][col-1];
    }
};