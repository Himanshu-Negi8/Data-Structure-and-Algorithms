#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
     
        int ans;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=0&&nums[i]!=0) 
            {
            	nums[i]=nums[i]*nums[i-1];	
			}
                
        }
        ans = *max_element(nums.begin(), nums.end());
        return ans;
}

int main()
{
	vector<int>nums;
	nums.push_back(0);
	nums.push_back(2);
	cout<<maxProduct(nums);
	cout<<-4*-3;
	return 0;
}
