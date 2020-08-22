//Jump Game

//recursive approach with backtrack 
class Solution {
public:
    bool helper(int pos, vector<int>& nums, int n){
        
        if(pos==n) return true;
        
        int furthestJump = min(pos+nums[pos], n);
        
        for(int nextPos=pos+1;nextPos<=furthestJump;nextPos++){
            if(helper(nextPos,nums,n)){
                return true;
            }
        }
        return false;
        
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        return helper(0,nums,n);
    }
};



//recursion with memoization
class Solution {
    int*memo;
public:
    
    bool helper(int pos, vector<int>& nums, int n){
        
        if(memo[pos] !=0) {
            return memo[pos]==1?true:false;
        }
        int furthestJump = min(pos+nums[pos], n);
        
        for(int nextPos=pos+1;nextPos<=furthestJump;nextPos++){
            if(helper(nextPos,nums,n)){
                memo[pos]=1;
                return true;
            }
        }
        memo[pos]=-1;
        return false;
        
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        memo = new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            memo[i]=0;
        }
        memo[n] =1;
        return helper(0, nums, n);
    }
};
