class Solution {
public:
    bool canConstruct( string ransomNote, string magazine ) {
        unordered_map<char, int> magazineLetterFreq;
        for( auto c : magazine )  magazineLetterFreq[c]++;
        for( auto c : ransomNote )  if( --magazineLetterFreq[c] < 0 ) return false;
        return true;
    }
};
