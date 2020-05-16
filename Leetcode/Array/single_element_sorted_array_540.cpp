class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;
        for(int i=0;i<nums.size();i++)
            {
             ans^=nums[i];
            
        }
        return ans;
    }
};
