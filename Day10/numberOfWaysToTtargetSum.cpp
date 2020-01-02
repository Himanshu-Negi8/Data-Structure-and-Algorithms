#include<iostream>
using namespace std;

 int targetSumWays(vector<int> nums,int si,int sum,int S)
    {
        if(si==nums.size())
        {
            if(sum==S){
                return 1;
            }else{
                return 0;
            }
        }
        int positive = targetSum(nums,si+1,sum+nums[si],S);
        int negative = targetSum(nums,si+1,sum-nums[si],S);
        
        return positive+negative;
    }
int findTargetSumWays(vector<int>& nums, int S) {
        
    unordered_map<string,int> h;
    return targetSum(nums,0,0,S,h);
}
    
int targetSum(vector<int> nums,int si,int sum,int S,unordered_map<string,int> &h){
    string key = to_string(si) + " " + to_string(sum);
        
    if(h.count(key)){
        return h[key];
    }
        
        // cout<<key<<endl;
        
    if(si==nums.size()){
        if(sum==S){
            return 1;
        }else{
            return 0;
        }
    }
        
        
    int positive = targetSum(nums,si+1,sum + nums[si],S,h);
    int negative = targetSum(nums,si+1,sum - nums[si],S,h);
        
    int total = positive + negative;
        
    h[key] = total;
        
    return total;
}
int main()
{
	int arr[]={1,1,1,1,1};
	int n=5;
	int sum=3;
	
	cout<<targetSumWays(arr,0,0,sum)<<endl;
	return 0;
}
