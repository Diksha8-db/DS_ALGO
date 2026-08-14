class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;

        for(int i = 0; i < 32; i++){
            int bit1 = (a >> i) & 1;  // get ith bit as 0/1
            int bit2 = (b >> i) & 1;
            
            int sum = bit1 ^ bit2 ^ carry;  // XOR gives sum bit
            carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry); // AND+OR gives carry

            if(sum == 1){
                res |= (1 << i);
            }
        }
        return res;
    }
};