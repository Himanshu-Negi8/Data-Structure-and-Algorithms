class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        vector<int>left_prod(nums.size());
        vector<int>right_prod(nums.size());
        
        vector<int>output(nums.size());
        
        left_prod[0]=1;
        right_prod[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            left_prod[i]=left_prod[i-1]*nums[i-1];
        }
        
        for(int i=nums.size()-2;i>=0;i--){
            right_prod[i]= right_prod[i+1]*nums[i+1];
        }
        
        for(int i=0;i<nums.size();i++){
            output[i]=left_prod[i]*right_prod[i];
        }
        return output;
    }
};
