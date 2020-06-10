class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start =0;
        int end = numbers.size()-1;
        vector<int>v(2);
        
        while(start<end){
            int sum=numbers[start]+numbers[end];
            if(sum==target){
                 v[0]=start+1;
                 v[1]=end+1;
                 
                return v;
                
            }
            else if(sum<target){
                start++;
            }
            
            else{
                end--;
            }
        }
        return v;
        
    
        
    }
};
