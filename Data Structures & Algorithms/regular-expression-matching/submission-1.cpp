class Solution {
public:
    int isPossible(string s, string p, int i, int j,vector<vector<int>>& dp){
        if(i == s.length() && j == p.length()){
            return 1;
        }
        if(j == p.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if(j+1 < p.length() && p[j+1] == '*'){
            return dp[i][j] = (isPossible(s,p,i,j+2,dp) || (match && isPossible(s,p,i+1,j,dp)));
        }
        if(match){
            return dp[i][j] = isPossible(s,p,i+1,j+1,dp);
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return isPossible(s,p,0,0,dp);
    }
};
