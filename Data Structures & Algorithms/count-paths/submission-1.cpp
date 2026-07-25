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
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return totalPath(1,1,m,n,dp);
    }
};
