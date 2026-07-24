class Solution {
public:
    vector<int> dp;
    int canBreak(string s, vector<string>& wordDict, int idx, int n){
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int i = idx; i < n; i++){
            string temp = s.substr(idx,i-idx+1);
            if(find(wordDict.begin(),wordDict.end(),temp) != wordDict.end()){
                // we got the substring
                if(canBreak(s,wordDict,i+1,n) == 1){
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        dp.resize(n+1,-1);
        return canBreak(s,wordDict,0,n);
    }
};
