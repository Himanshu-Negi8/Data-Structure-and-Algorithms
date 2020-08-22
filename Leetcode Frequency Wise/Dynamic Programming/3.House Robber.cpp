//Recursive approach trying to find all possible ways of get max
class Solution {
public:
    
    int helper(vector<int>& nums,int i){
        if(i>=nums.size()) return 0;
        
       
        int ans=0;
        //if ith is chosen then we can only choose i+2
        
        int res = nums[i]+helper(nums,i+2);
        //ignore the current 
        int ignore = helper(nums,i+1);
        
        ans=max(res,ignore);
        return ans;
        
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        
    
        
        return helper(nums,0);
       
        
    }
};

//memoize the code
class Solution {
    
    
public:
    
    int helper(vector<int>& nums,int i, vector<int>& dp){
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        //if ith is chosen then we can only choose i+2
        int res = nums[i]+helper(nums,i+2,dp);
        //ignore
        int ignore = helper(nums,i+1,dp);
        
        dp[i]=max(res,ignore);
        return dp[i];
        
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        
        vector<int>dp(nums.size(),-1);
        
        return helper(nums,0,dp);
 
        
    }
};

//pure dp solution maintain a running max element as well as the also computing and comparing with nums[i] and i+2
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        else if(nums.size()==1) return nums[0];
        
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        
        for(int i=2;i<nums.size();i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[nums.size()-1];
    }
};
