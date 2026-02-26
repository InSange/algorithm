class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool OutBounds(int y, int x, int row, int col)
    {
        return y < 0 || x < 0 || y >= row || x >= col;
    }

    bool dfs(vector<vector<char>>& board, string& word, int curY, int curX, int index)
    {
        if(index == word.length()) return true;

        for(int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i], nextX = curX + dx[i];
            if(OutBounds(nextY, nextX, board.size(), board[0].size())) continue;
            if(board[nextY][nextX] != word[index]) continue;

            board[nextY][nextX] = '#';
            if(dfs(board, word, nextY, nextX, index + 1)) return true;
            board[nextY][nextX] = word[index];
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
       for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] != word[0]) continue;
                board[i][j] = '#';
                if(dfs(board, word, i, j, 1)) return true;
                board[i][j] = word[0];
            }
        }

       return false;
    }
};