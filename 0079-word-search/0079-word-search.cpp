class Solution {
public:
    vector<vector<bool>> visited;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool OutBounds(int y, int x, int row, int col)
    {
        return y < 0 || x < 0 || y >= row || x >= col;
    }

    bool dfs(const vector<vector<char>>& board, string word, int curY, int curX, int index)
    {
        if(index == word.length()) return true;

        for(int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i], nextX = curX + dx[i];
            if(OutBounds(nextY, nextX, board.size(), board[0].size())) continue;
            if(board[nextY][nextX] != word[index]) continue;
            if(visited[nextY][nextX]) continue;

            visited[nextY][nextX] = true;
            if(dfs(board, word, nextY, nextX, index + 1)) return true;
            visited[nextY][nextX] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
       visited.assign(board.size(), vector<bool>(board[0].size(), false));

       for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] != word[0]) continue;
                visited[i][j] = true;
                if(dfs(board, word, i, j, 1)) return true;
                visited[i][j] = false;
            }
        }

       return false;
    }
};