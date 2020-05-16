class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_sum=INT_MIN,max_till_now=0;
        
        for(int i=0;i<nums.size();i++)
        {
            max_till_now +=nums[i];
            if(max_sum<max_till_now)
            {
                max_sum=max_till_now;
            }
            
            if(max_till_now<0)
            {
                max_till_now=0;
            }
            
        }
        return max_sum;
    }
};
