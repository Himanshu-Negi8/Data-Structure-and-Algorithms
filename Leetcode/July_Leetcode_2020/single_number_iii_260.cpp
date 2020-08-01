class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto a:mp){
            if(a.second==1){
                v.push_back(a.first);
            }
        }
        return v;
    }
};
