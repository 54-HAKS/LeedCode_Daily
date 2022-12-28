class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val=0;
        // let's say that we have an array [a,a,b,c,c,d]
        for(int num:nums) val ^= num;
        // after xor all of them, the result val = b^d
        // let's say that b^d = 3 = 0011. this means that b and d are different in the last two bit positions
        // one can partition the entire array with either of the two bits. let's say we use bit 0.
        // Then, some numbers have 1 in bit 0, and the others have 0 at bit 0.
        /* the remaining question is how to get an number that is 0001, or 0010. It is actually easy to get 0001, one can just do val = val&-val, since -val is the two's compliment of val. When val = 3 = 0011, its 2's compliment is 1100+0001 = 1101. and val&-val will give 0001. It is always true that val & -val will result in the lowest bit that equals 1. so here we go.*/
        val &= -val;
        vector<int> ret(2,0);
        for(int num:nums) {
            if(num&val) ret[0] ^= num;
            else ret[1] ^= num;
        }
        return ret;
    }
};