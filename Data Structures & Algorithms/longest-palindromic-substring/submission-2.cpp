class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 0;
        int start = 0;

        // Loop i backwards so bottom-up subproblems (i+1) are ready
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        
                        if (j - i + 1 > maxLen) {
                            maxLen = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};