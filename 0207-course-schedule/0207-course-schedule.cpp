class Solution {
public:
bool dfs(int node, vector<int>adj[],vector<int>&vis,vector<int>&path){
    vis[node]=1;
    path[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,path)==true)return true;
        }
        else if(path[it])return true;
    }
    path[node]=0;
    return false;
}
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>adj[n];
        for(int i =0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)==true)return false;
            }
        }
        return true;
    }
};