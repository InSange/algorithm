class Solution {
public:
    vector<int> parent;

    int GetParent(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = GetParent(parent[x]);
    }
    bool IsCycle(int a, int b)
    {
        int parentA = GetParent(a);
        int parentB = GetParent(b);

        if(parent[a] == parent[b]) return true;

        if(parentA < parentB) parent[parentB] = parentA;
        else parent[parentA] = parentB;

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 하나의 사이클 존재 -> 정점의 개수 = 간선의 개수
        int n = edges.size();
        
        parent.assign(n+1, 0);

        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        int i = 0;
        for(i ; i < n; i++)
        {
            int a = edges[i][0], b = edges[i][1];
            if(IsCycle(a, b)) return edges[i];
        }

        return edges[i];
    }
};