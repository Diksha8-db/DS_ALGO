class Solution {
public:
    vector<vector<int>> dp;
    int isPossible(int i, int j, string s1, string s2, string s3){
        // base case
        if(i == s1.length() && j == s2.length()) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int res = 0;
        if(i < s1.length() && s1[i] == s3[i+j]){
            res = isPossible(i+1,j,s1,s2,s3);
        }
        if(j < s2.length() && s2[j] == s3[i+j]){
            res = isPossible(i,j+1,s1,s2,s3);
        }
        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if(n+m != s3.length()) return false;
        
        dp.resize(n+1,vector<int>(m+1,-1));
        return ((isPossible(0,0,s1,s2,s3) == 0) ? false : true);
    }
};
