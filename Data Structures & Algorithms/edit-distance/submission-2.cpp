class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int minDist(int i, int j, string w1, string w2){
        if(i == n && j == m) return 0;
        if(i >= n) return (m-j);
        if(j >= m) return (n-i);

        if(dp[i][j] != -1) return dp[i][j];
        // check if matched
        if(w1[i] == w2[j]){
           return dp[i][j] = minDist(i+1,j+1,w1,w2);
        }
        int replace = 1 + minDist(i+1,j+1,w1,w2);
        int del = 1 + minDist(i+1,j,w1,w2);
        int insert = 1 + minDist(i,j+1,w1,w2);

        return dp[i][j] = min({replace,del,insert});
    }
    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();

        dp.resize(n+1,vector<int>(m+1,-1));
        return minDist(0,0,word1,word2);
    }
};
