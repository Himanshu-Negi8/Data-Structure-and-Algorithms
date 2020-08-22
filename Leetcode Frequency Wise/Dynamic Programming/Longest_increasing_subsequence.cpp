#include<bits/stdc++.h>
using namespace std;


int lis(int arr[],int n){
	
	int*output = new int[n];
	output[0]=1;
	
	for(int i=1;i<n;i++){
		output[i]=1;
		for(int j=i-1;j>=0;j--){
			if(arr[j]>arr[i]){
				continue;
			}
			int possibleAns = output[j]+1;
			if(possibleAns>output[i]){
				output[i]=possibleAns;
			}
		}
	}
	int best = *max_element(output,output + n);
	return best;
}
int main(){
	
	int n;
	cin>>n;
	int*arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int ans = lis(arr,n);
	cout<<ans;
	return 0;
}


//class Solution {
//public:
//    int helper(vector<int> nums, int prev,int curr){
//        if(curr==nums.size()) return 0;
//        
//        int include =0;
//        if(nums[curr]>prev){
//            include+=1+helper(nums,nums[curr],curr+1);
//            
//        }
//        int exclude = helper(nums,prev,curr+1);
//        return max(include,exclude);
//    }
//    int lengthOfLIS(vector<int>& nums) {
//        return helper(nums,INT_MIN,0);
//    }
//};
