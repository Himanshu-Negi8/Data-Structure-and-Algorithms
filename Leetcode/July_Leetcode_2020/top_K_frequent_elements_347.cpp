class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            ++mp[nums[i]];
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto a:mp){
            pq.push(make_pair(a.second,a.first));
        }
        
        
        for(int i=1;i<=k;i++){
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }
};
