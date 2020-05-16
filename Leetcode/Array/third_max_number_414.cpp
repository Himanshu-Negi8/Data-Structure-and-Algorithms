class Solution {
public:
    int thirdMax(vector<int>& nums) {
     
        if(nums.size()<3){
            return *max_element(nums.begin(),nums.end());
        }
        
        int first_max = INT_MIN,second_max=INT_MIN,third_max=INT_MIN;
      
        for(int i=0;i<nums.size();i++){
            if(nums[i]==INT_MIN){
                nums[i]=nums[i]+1;
            }
            if(nums[i]>first_max){
                third_max = second_max;
                second_max=first_max;
                first_max=nums[i];
            }
           
            else if(second_max<nums[i]&&nums[i]<first_max){
                
                third_max=second_max;
                second_max=nums[i];
            }
            else if(third_max<nums[i]&&nums[i]<second_max){
                third_max=nums[i];
            }
        }
        
        if(third_max==INT_MIN){
            return first_max;
        }
    
        if(third_max==INT_MIN+1){
            return INT_MIN;
       }
    
        return third_max;
    
    }
};
