class Solution {
public:
    
    int searchRotated(vector<int>&nums,int start,int end,int data)
    {
        if(start>end){
        return -1;
    }

	int mid = start+(end-start)/2;

	if(nums[mid]==data){
		return mid;
	}

	if(nums[start]<=nums[mid]){

		if(nums[start]<=data and data<nums[mid]){
			return searchRotated(nums,start,mid-1,data);
		}else{
			return searchRotated(nums,mid+1,end,data);
		}

	}else{

		if(nums[mid] < data and data <=nums[end]){

			return searchRotated(nums,mid+1,end,data);

		}else{
			return searchRotated(nums,start,mid-1,data);
		}
	}
}
    
    int search(vector<int>& nums, int target) {
       
        int data =target;
        int start =0;
        int end=nums.size()-1;
         return searchRotated(nums,start,end,data);
    }
    
};
