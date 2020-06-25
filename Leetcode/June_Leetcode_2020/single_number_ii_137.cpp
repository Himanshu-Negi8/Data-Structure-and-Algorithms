class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
		int a;
		unordered_map<int,int> g;
		
		for(int i=0;i<n;i++){
		g[nums[i]]++;
		}
		
		for(int i=0;i<n;i++){
			
			if(g[nums[i]]==1){
			a = nums[i];
			break;
			}
		}
		return a;
    }
};
