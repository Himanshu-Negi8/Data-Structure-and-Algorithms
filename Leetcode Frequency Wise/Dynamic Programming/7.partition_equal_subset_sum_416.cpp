
/**** Recursive Code ***/
class Solution {
public:
    bool helper(vector<int> nums, int idx, int sum, int total){
        if(sum==total) return true;
        
        if(sum>total or idx>=nums.size()) return false;
        
        bool include = helper(nums,idx+1,sum+nums[idx],total);
        bool exclude = helper(nums,idx+1,sum,total);
        
        return include||exclude;
        
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        
        return helper(nums,0,0,sum/2);
    }
};


/***** Dp with memoization *****/

class Solution {
public:
    unordered_map<string,bool>mp;
    bool helper(vector<int> nums, int idx, int sum, int total){
        string current = to_string(idx)+""+to_string(sum);
        if(mp.count(current)){
            return mp[current];
        }
        if(sum==total) return true;
        
        if(sum>total or idx>=nums.size()) return false;
        
        bool res = helper(nums,idx+1,sum+nums[idx],total)||helper(nums,idx+1,sum,total);
        mp[current]=res;
        return res;
        
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        
        return helper(nums,0,0,sum/2);
    }
};
