struct TrieNode {
    TrieNode* next[26];
    string* word;

    TrieNode() {
        for(int i = 0; i < 26; i++) next[i] = nullptr;
        word = nullptr;
    }
    
     ~TrieNode() {
        for (int i = 0; i < 26; i++)
            if (next[i]) delete next[i];
    }
};

class Solution {
public:
    void insert(TrieNode* root, string& s) { 
        TrieNode* temp = root;

        for(auto& c : s)
        {
            if(temp->next[c-'a'] == nullptr) temp->next[c-'a'] = new TrieNode();
            temp = temp->next[c-'a'];
        }

        temp->word = &s;
     }

     void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, TrieNode* node, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j]) 
            return;

        char c = board[i][j];
        int idx = c - 'a';

        if (node->next[idx] == nullptr) 
            return;

        node = node->next[idx];

        if (node->word != nullptr) {
            result.push_back(*(node->word));
            node->word = nullptr;
        }

        visited[i][j] = true;

        dfs(board, visited, i + 1, j, node, result);
        dfs(board, visited, i - 1, j, node, result);
        dfs(board, visited, i, j + 1, node, result);
        dfs(board, visited, i, j - 1, node, result);

        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(string& word : words)
        {
            insert(root, word);
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<string> result;

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                dfs(board, visited, i, j, root, result);
            }
        }

        return result;
    }
};