class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int n,m;
    int dfs(int r, int c, vector<vector<int>>& matrix){
        if(dp[r][c] != 0) return dp[r][c];

        int totalWay = 1;
        for(int i = 0; i < 4; i++){
            int newr = r + dir[i][0];
            int newc = c + dir[i][1];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m){
                if(matrix[newr][newc] > matrix[r][c]){
                    totalWay = max(totalWay, 1 + dfs(newr,newc,matrix));
                }
            }
        }

        return dp[r][c] =  totalWay;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxVal = INT_MIN;
        n = matrix.size();
        m = matrix[0].size();

        dp.resize(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxVal = max(maxVal,dfs(i,j,matrix));
            }
        }
        return maxVal;
    }
};
