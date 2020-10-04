
//brute force approach
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0 or nums.size()==1) return false;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j] and abs(i-j)<=k){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//better approach 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0 or nums.size()==1) return false;
        
        map<int,vector<int>>mp;
        
        //store the indices basically 
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        
        
        
        for(auto a:mp){
        	//if list indices vector size is atleast 2 than we can find the distinct indices difference
            if(a.second.size()>=2)
                for(int i=0;i<a.second.size()-1;i++){
                    if(abs(a.second[i]-a.second[i+1])<=k) return true;
                }

	    }   
        
        return false;
    }
};

//compact one same as better approach


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++) 
        {
            if((m.find(nums[i]) != m.end()) && (i-m[nums[i]] <= k)) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};
