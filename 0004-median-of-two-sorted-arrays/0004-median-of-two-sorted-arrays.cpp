class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(auto n : nums1) v.push_back(n);
        for(auto n : nums2) v.push_back(n);
        
        sort(v.begin(), v.end());
        double answer;
        int mid = v.size()/2;
        if(v.size() % 2 == 1)
        {
            answer = v[mid];
        }
        else
        {
            double num = (v[mid] + v[mid-1]); 
            answer = num/2;
        }
        return answer;
    }
};