class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i = 0; i <= n; i++){
            // count the number of set bits
            int setCount = 0;
            for(int pos = 31;pos >= 0; pos--){
                if((i & (1 << pos))!= 0) setCount++;
            }

            ans[i] = setCount;
        }
        return ans;
    }
};
