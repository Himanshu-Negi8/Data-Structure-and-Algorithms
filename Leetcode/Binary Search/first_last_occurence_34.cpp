class Solution {
public:
    int lastOccurence(vector<int>&arr,int n,int data)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	while(start<=end)
	{
		int mid =(start+end)/2;
		if(arr[mid]==data)
		{
            ans=mid;
			start=mid+1; //for last occurence
			
		}
		else if(arr[mid]>data)
		{
			end = mid-1;
		}
		else
		{
			start=mid+1;
		}
		
	}
	return ans;
}
int firstOccurence(vector<int>&arr,int n,int data)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	while(start<=end)
	{
		int mid =(start+end)/2;
		if(arr[mid]==data)
		{
			ans = mid;
			end = mid-1; //for first occurence
		
			
		}
		else if(arr[mid]>data)
		{
			end = mid-1;
		}
		else
		{
			start=mid+1;
		}
		
	}
	return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2);
        res[0]=firstOccurence(nums,nums.size(),target);
        res[1]=lastOccurence(nums,nums.size(),target);
        return res;
        
    }
};
