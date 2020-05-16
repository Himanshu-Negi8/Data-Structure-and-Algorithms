class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mp;
        
        for(int x:nums)
        {
            ++mp[x];
        }
        
        for(auto p:mp)
        {
            if(p.second>1){
                return true;
            }
        }
        return false;
    }
};
