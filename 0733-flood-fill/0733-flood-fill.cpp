class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startValue = image[sr][sc];
        
        vector<vector<int>> answer(image);
        vector<vector<bool>> visited;
        visited.assign(image.size(), vector<bool>(image[0].size(), false));

        cout << visited.size() << ", " << visited[0].size();
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        visited[sr][sc] = true;
        answer[sr][sc] = color;
        
        while(!q.empty())
        {
            int y, x;
            y = q.front().first;
            x = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int ny, nx;
                ny = y + dy[i];
                nx = x + dx[i];
                
                if(ny < 0 || ny >= image.size() || nx < 0 || nx >= image[0].size() || visited[ny][nx]) continue;
                if(image[ny][nx] == startValue)
                {
                    answer[ny][nx] = color;
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
        
        return answer;
    }
};