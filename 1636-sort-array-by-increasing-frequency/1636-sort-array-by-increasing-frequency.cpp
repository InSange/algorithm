class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        vector<int> output;
        unordered_map<int,pair<int,int>> mp;
        for(auto& i : nums){
            if(mp.find(i)!=mp.end()){
                mp[i].first++;
                continue;
            }
            
            mp[i]={1,i};
        }
        
        vector<pair<int,int>> freq;
        for(auto& p : mp){
            freq.push_back({p.second.first,p.first});
        }
        
        sort(freq.begin(),freq.end(),[](const pair<int,int>&a , const pair<int,int>&b){
            if(a.first==b.first){
                return a.second>b.second; //sort in desending order if frequency is same
            }
           return  a.first<b.first;
        });
        
        for(auto& pair : freq){
           
            for(int i=0;i<pair.first;i++){
                output.push_back(pair.second);
            }
            
            
          
        }
        
        
        return output;
        
    }
};