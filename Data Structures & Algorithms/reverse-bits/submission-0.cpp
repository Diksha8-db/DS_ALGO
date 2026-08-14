class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for(int i = 31; i >= 0; i--){
            // extract the bit value at pos i
            int bit = (n & (1 << i));

            // now put this bit on the position (31-i)
            if(bit != 0){
                // set the bit at pos (31-i)
                res |= (1 << (31-i));
            }
        }

        return res;
    }
};
