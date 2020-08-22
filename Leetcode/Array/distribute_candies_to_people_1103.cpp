class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        vector<int>ans(n,0);
		//if there is only one candy so give it to the first person
        if(candies==1){
            ans[0]=1;
            return ans;
        }
		// if there is 1 person give all candies to him
        if(num_people==1) return {candies};
        // i=0 initially denotes doing first iteration 
        int i=0,j=1;
        int index =0;
        while(candies!=0){
		
			// n*i+j denotes at which iteration we are and how much we can distribute at particular index
           int distribute = n*i+j;
            
			//if number of candies are more than to be distributed assign it to the curr index
            if(candies>=distribute){
                ans[index] = ans[index]+distribute;
                candies -=distribute;
                ++index; 
                j++;
				
				//if we reaches the last index we have to set index =0 to start again
				
                if(index==num_people){
                    index=0;
                    j=1;
                    ++i;
                }
            }
		/*
			if there are not enough candies to be distibuted then 
			assign it to the curr_index and make candies as 0
		*/
            else if(candies){
                ans[index++]+=candies;
                candies=0;
            }
            
          
            
        }
        return ans;
    }
};
