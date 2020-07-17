
        
    class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>b = {n}; 
        int right = 0,left=31; 
        while(right < left){
			int t  = b[right];
            b[right++] = b[left];
            b[left--] = t;
        }
        return b.to_ulong();

    }
};

