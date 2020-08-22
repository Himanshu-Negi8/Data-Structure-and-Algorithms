class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int>v;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        //assigning the indexing as value to key of val in map 
        mp[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        
        swap(v[mp[val]],v[v.size()-1]);
        v.pop_back();
        
        /*
		 lets say 1 2 3 in the vector and request of remove is for 2 then swap the last index value with index of mp[2] 
		 then pop_back it as pop_back in vector is o(1) operation then update the key of new value at v[mp[val]] i.e is
		 v[mp[2]] -> v[1]-> 3 
		 mp[3] = mp[2] =1;
		 
		*/
        mp[v[mp[val]]]=mp[val]; //assigning the new key value for value at index mp[val] i.e v[mp[val]] after swap 
        mp.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
