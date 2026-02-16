class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& pre : prerequisites)
        {
            int u = pre[1];
            int v = pre[0];

            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            cnt++;

            for(int next : graph[cur])
            {
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        return cnt == numCourses;
    }
};