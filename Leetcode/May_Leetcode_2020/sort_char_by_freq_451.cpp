class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        
        for(char c:s){
            mp[c]++;
        }
       priority_queue<pair<int, char>> maxHeap;
       for( auto p : mp )
            maxHeap.push( { p.second, p.first } );

        string result = "";
        while( !maxHeap.empty() ) {
            auto p = maxHeap.top(); maxHeap.pop();
            while( p.first-- )
                result += p.second;
        }
	return result;
    }
};
