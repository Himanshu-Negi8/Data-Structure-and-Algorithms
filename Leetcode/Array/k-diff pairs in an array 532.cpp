class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(k<0) return 0;
        
        map<int,int>mp;
        
        for(int n:nums) mp[n]++;
        
        int count =0;
        
        for(auto temp : mp){
            if(!k and temp.second>1 or (k and mp.count(temp.first+k))) count++;
        }
        
        return count;
    }
};
