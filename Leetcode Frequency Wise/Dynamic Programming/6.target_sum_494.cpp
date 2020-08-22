/*Recursive code*/

class Solution {
public:
    int helper(vector<int>& nums, int i, int sum, int S){
        if(i==nums.size()){
            if(sum==S) return 1;
            else return 0;
            
        }
        
        int positive = helper(nums,i+1,sum+nums[i],S);
        int negative = helper(nums,i+1,sum-nums[i],S);
        
        return positive+negative;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums,0,0,S);
    }
};


/* memoization */


class Solution {
public:
    int helper(vector<int>& nums, int i, int sum, int S, unordered_map<string,int> &h){
        string key = to_string(i)+" "+to_string(sum);
        
        if(h.count(key)){
            return h[key];
        }
        
        if(i==nums.size()){
            if(sum==S) return 1;
            else return 0;
            
        }
        
        int positive = helper(nums,i+1,sum+nums[i],S,h);
        int negative = helper(nums,i+1,sum-nums[i],S,h);
        
        int total = positive+negative;
        h[key] = total;
        return total;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<string,int>h;
        return helper(nums,0,0,S,h);
    }
};
