class Solution {
public:
    int totalPath(int i, int j, int r, int c,vector<vector<int>>& dp){
        if(i == r && j == c){
            return 1; // base case (destination is reached)
        }

        if(dp[i][j] != -1) return dp[i][j];

        int right = ((i+1 <= r) ? totalPath(i+1,j,r,c,dp) : 0);
        int down = ((j+1 <= c) ? totalPath(i,j+1,r,c,dp) : 0);
        return dp[i][j] = right+down;
    }
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int i = 0; i < n; i++)
            dp[m][i] = 1;
        
        for(int j = 0; j < m; j++)
            dp[j][n] = 1;

        for(int i = m-1; i >= 1; i--){
            for(int j = n-1; j >= 1; j--){
                int right = 0, down = 0;
                // right dir total ways
                if(i+1 <= m) right = dp[i+1][j];
                // down dir total ways
                if(j+1 <= n) down = dp[i][j+1];

                dp[i][j] = right+down;
            }
        }
        // return totalPath(1,1,m,n,dp);
        return dp[1][1];
    }
};
