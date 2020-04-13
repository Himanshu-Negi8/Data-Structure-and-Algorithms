#include<bits/stdc++.h>
using namespace std;

    int firstMissingPositive(vector<int>& nums) {
        
        int array_sum;
        int n = nums.size();
        int series_sum = (n*(n+1));
        series_sum/=2;
        for(int i=0;i<nums.size();i++)
        {
        	if(nums[i]>0)
        	{
        		array_sum+=nums[i];
			}
		
            
        }
        
        return series_sum-array_sum;
        
    }


int main()
{
	char *s= new char[50];
	vector<int>nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	cout<<firstMissingPositive(nums);
	
	return 0;
}
