class Solution {
public:
    int missingNumber(vector<int>& nums) {
    
        int n = nums.size();
        int total = (n*(n+1))/2;
        int sum=0;
        
        for(int a:nums){
            sum+=a;
        }
        return total-sum;
        
        
    }
};
