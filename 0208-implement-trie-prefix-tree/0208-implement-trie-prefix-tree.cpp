class Trie {
private:
    struct TrieNode
    {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false; 
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr; 
            }
        }
    };

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;

        for(auto& c : word)
        {
            if(temp->child[c-'a'] == nullptr)
            {
                TrieNode* newNode = new TrieNode();

                temp->child[c-'a'] = newNode;
            }

            temp = temp->child[c-'a'];
        }

        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;

        for(auto& c : word)
        {
            if(temp->child[c-'a'] == nullptr) return false;
            temp = temp->child[c-'a'];
        }

        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for(auto& c : prefix)
        {
            if(temp->child[c-'a'] == nullptr) return false;
            temp = temp->child[c-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */