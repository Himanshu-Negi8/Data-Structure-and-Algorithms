class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1 and nums[0]==1){
            return 1;
        }
        int current=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                current+=1;
            }else{
                ans = max(ans,current);
                current=0;
            }
            
            
        }
        ans = max(ans,current);
        return ans;
    }
};
