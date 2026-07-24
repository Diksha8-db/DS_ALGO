class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        // 1 and 2 length substrings
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(i == j) dp[i][j] = true;
                if(j-i+1 == 2){
                    dp[i][j] = ((s[i] == s[j]) ? true : false);
                }
            }
        }

        // for string greater than 3 length
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j-i+1 >= 3){
                    dp[i][j] = ((s[i] == s[j] && dp[i+1][j-1]) ? true : false);
                }
            }
        }

        // count the total number of valid substring that are aplindrome
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j<n; j++){
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};
