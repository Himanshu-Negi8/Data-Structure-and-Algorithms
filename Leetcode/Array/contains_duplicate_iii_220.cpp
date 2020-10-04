class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
       vector<pair<int,int>>v;
        if(nums.size()<=1) 
            return false;
       for (int i = 0; i < nums.size(); ++i)
       {
       	v.push_back(make_pair(nums[i] ,i ));
       }
       sort(v.begin(), v.end());


        for(int i = 0 ; i < nums.size() ; i++){
            
            int j = i+1;
            long int x = INT_MIN;
            while(x <= t&&j<nums.size()){
            	 	long int a = v[i].first;
                    long int b = v[j].first;
                    x = abs(a-b);

                    long int y = abs(v[i].second-v[j].second);
                    if(x <= t && y <= k)
                    return true;
                    j++;
            }          
            
        }
        return false;
    }
};
