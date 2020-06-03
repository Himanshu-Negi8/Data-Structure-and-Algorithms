/*

1365. How Many Numbers Are Smaller Than the Current Number

Brute-force Solution

*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v(nums.size());
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]>nums[j] && i!=j){
                    count+=1;
                }
            }
            v[i]=count;
        }
        return v;
    }
};
