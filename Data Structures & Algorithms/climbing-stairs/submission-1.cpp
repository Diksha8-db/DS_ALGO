class Solution {
public:
    /*
    // APPROACH 1: RECURSION (T.C = O(2^n))
    int countStairs(int curr,int n){
        // base case
        if(curr == n){
            // dest reached
            return 1;
        }

        if(curr > n) return 0; // not possible
        int choseOne = countStairs(curr+1,n);
        int choseTwo = countStairs(curr+2,n);
        return choseOne + choseTwo;
    }
    */
    int climbStairs(int n) {
        if(n <= 2) return n;
        // return countStairs(0,n);

        // APPROACH 2 : T.C = O(n) and S.C = O(n)
        /*
        vector<int> dp(n+1);
        dp[2] = 2, dp[1] = 1;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        */

        // APPROACH 3 : T.C = O(n) and S.C = O(1)
        int oneStep = 1;
        int twoStep = 2;
        for(int i = 3; i <= n; i++){
            int temp1 = oneStep + twoStep;
            oneStep = twoStep;
            twoStep = temp1;
        }

        return twoStep;
    }
};
