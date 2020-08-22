
//brute force by generating all subarray
	for(int start=0;start<4;start++)
	{
		for(int end=start;end<4;end++)
		{
			int sum =0;
			for(int k=start;k<=end;k++)
			{
				sum+=arr[k];

			}
			if(sum==k){
				count++;
			}

		}
	}
	
	cout<<count;



/*
Approach 2: Using Cumulative Sum
Algorithm

Instead of determining the sum of elements everytime for every new subarray considered, we can make use of a cumulative sum array , sumsum. Then, in order to calculate the sum of elements lying between two indices, we can subtract the cumulative sum corresponding to the two indices to obtain the sum directly, instead of iterating over the subarray to obtain the sum.

In this implementation, we make use of a cumulative sum array, sumsum, such that sum[i]sum[i] is used to store the cumulative sum of numsnums array upto the element corresponding to the (i-1)^{th}(i-1) 
th
  index. Thus, to determine the sum of elements for the subarray nums[i:j]nums[i:j], we can directly use sum[j+1] - sum[i]sum[j+1]-sum[i].
*/ 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int count = 0;
        int * sum = new int[nums.size() + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
};

/*
Approach 3: Without Space
Algorithm

Instead of considering all the startstart and endend points and then finding the sum for each subarray 
corresponding to those points, we can directly find the sum on the go while considering different endend points. 
i.e. We can choose a particular startstart point and while iterating over the endend points, we can add the element 
corresponding to the endend point to the sum formed till now. Whenver the sumsum equals the required kk value, 
we can update the countcount value. We do so while iterating over all the endend indices possible for every startstart index.
 Whenver, we update the startstart index, we need to reset the sumsum value to 0.
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0;
        for(int start=0;start<nums.size();start++){
            int sum=0;
            for(int end=start;end<nums.size();end++){
                sum+=nums[end];
                if(sum==k) count++;
            }
        }
        
        return count;
    }
};


/*
	 
	 Approach-4
	 if running sum is directly meet the condition then increment the count
	 if you have found the corrosponding num of current sum that means
	 dependent and independent one make sum to k then increase the count

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0,sum=0;
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            if(sum==k) count++;
            
            if(mp.find(sum-k)!=mp.end()) count+=mp[sum-k];
            
            mp[sum]++;
        }
        
        return count;
    }
};
