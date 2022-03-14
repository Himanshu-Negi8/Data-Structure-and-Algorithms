class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>v;
	unordered_map<string,vector<string>> mp;
	
	for(string x:strs){
		auto word =x;
		sort(x.begin(),x.end());
		mp[x].push_back(word);
	}
		
	for( auto a : mp){
		v.push_back(a.second);
	}
	
        return v;
    }
};
