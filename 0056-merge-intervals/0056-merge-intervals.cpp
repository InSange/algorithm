class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        vector<vector<int>> answer;
        int left = 0, right = 1;
        while(right <= intervals.size())
        {
            vector<int> cur(intervals[left]);

            while((right < intervals.size()) && (cur[1] >= intervals[right][0]))
            {
                if(intervals[right][1] > cur[1]) cur[1] = intervals[right][1];
                right++;
            }

            answer.push_back(cur);
            left = right;
            right++;
        }

        return answer;
    }
};