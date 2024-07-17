/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<TreeNode*> ans;
    unordered_map<int, bool> visited;
    
    void dfs(TreeNode* &root, bool flag){
        if (root == nullptr) return;
        dfs(root->left, visited[root->val]);
        dfs(root->right, visited[root->val]);
        if (!visited[root->val] && flag) ans.push_back(root);
        if (visited[root->val]) root = nullptr;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(auto val : to_delete)
        {
            visited[val] = true;
        }
        
        dfs(root, true);
        
        return ans;
    }
};