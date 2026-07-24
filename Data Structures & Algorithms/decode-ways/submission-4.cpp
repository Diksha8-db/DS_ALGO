class Solution {
public:
    vector<int> dp;
    int findWays(int i, string s){
        // base case
        if(i >= s.length()) return 1;
        if(dp[i] != -1) return dp[i];

        if(s[i] == '0') return 0;
        int currPick;
        if(s[i] != '0') currPick = findWays(i+1,s);

        int twoPick = 0;
        if(i+1 < s.length()) {
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num >= 10 && num <= 26) twoPick = findWays(i+2,s);
        }

        return dp[i] = currPick+twoPick;
    }
    int numDecodings(string s) {
        // if there is any 0 in the start of string that means the valid answer is not possible
        if(s[0] == '0') return 0;
        int n = s.length();
        dp.resize(s.length()+1,-1);

        // int count = findWays(0,s);
        dp[n] = 1;
        dp[n-1] = (s[n-1] == '0') ? 0 : 1; 
        for(int i = n-2; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            int currPick = dp[i+1];
            int twoPick = 0;
            if(i+1 < s.length()) {
                int num = (s[i]-'0')*10 + (s[i+1]-'0');
                if(num >= 10 && num <= 26) twoPick = dp[i+2];
            }

            dp[i] = currPick+twoPick;
        }
        return findWays(0,s);
    }
};
