class Solution {
public:
    int lcs(int i, int j, string s1,string s2,vector<vector<int>>& dp){
        if(i >= s1.length() || j >= s2.length()) return 0; // no more match can be found

        if(dp[i][j] != -1) return dp[i][j];

        int matched = 0, notMatched = 0;
        if(s1[i] == s2[j]){
            matched = 1+lcs(i+1,j+1,s1,s2,dp); // count increases by 1 now count ahead
        }
        else{
            notMatched = max(lcs(i+1,j,s1,s2,dp),lcs(i,j+1,s1,s2,dp));
        }

        return dp[i][j] = max(matched,notMatched);
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // return lcs(0,0,text1,text2,dp);

        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};
