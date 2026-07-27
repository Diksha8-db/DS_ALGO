class Solution {
public:
    vector<vector<int>> dp;

    int totalCount(int i, int j, string &s, string &t) {
        // Base case 
        if (j == t.length()) return 1;

        if (i == s.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int result = 0;
        if (s[i] == t[j]) {
            result = totalCount(i + 1, j + 1, s, t) + totalCount(i + 1, j, s, t);
        } else {
            result = totalCount(i + 1, j, s, t);
        }

        return dp[i][j] = result;
    }

    int numDistinct(string s, string t) {
        dp.resize(s.length(), vector<int>(t.length(), -1));
        return totalCount(0, 0, s, t);
    }
};
