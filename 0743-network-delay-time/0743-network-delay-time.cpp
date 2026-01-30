class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> v(n + 1, vector<pair<int, int>>());
        vector<int> visited(n + 1, -1);

        for(const auto& time : times)
        {
            v[time[0]].push_back({time[2], time[1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty())
        {   // first = time, second = index
            pair<int, int> cur = pq.top();
            pq.pop();
            if(visited[cur.second] != -1 && visited[cur.second] <= cur.first) continue;
            visited[cur.second] = cur.first;
            for(const auto& next : v[cur.second])
            {
                if(visited[next.second] == -1 || visited[next.second] >= (cur.first + next.first))
                {
                    pq.push({cur.first + next.first, next.second});
                }
                
            }
        }

        int answer = 0;
        for(int i = 1; i <= n; i++)
        {
            if(visited[i] == -1) return -1;
            answer = max(visited[i], answer);
        }

        return answer == 0 ? -1 : answer;
    }
};