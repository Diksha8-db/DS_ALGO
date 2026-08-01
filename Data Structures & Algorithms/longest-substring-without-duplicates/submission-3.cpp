class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // APPROACH 1 : Brute Force (T.C = O(n^2) and S.C = O(n))
        /*
        int maxLen = INT_MIN;

        for(int i = 0; i < n; i++){
            set<char> freqSet;
            for(int j = i; j < n; j++){
                // check if this character is present in the substring or not
                if(freqSet.count(s[j])){
                    break; // start the next iteration
                }
                else{
                    freqSet.insert(s[j]);
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }

        return (maxLen == INT_MIN) ? 0 : maxLen;
        */

        if(n == 0) return 0;
        int maxLen = INT_MIN;

        // push the elements in mpp till duplication starts
        unordered_map<char,int> mpp;
        int i = 0,j = 0;

        while(j < n){
            if(mpp.find(s[j]) != mpp.end() && mpp[s[j]] >= i){
                i = mpp[s[j]] + 1;
            }
            mpp[s[j]] = j;
            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return (maxLen == INT_MIN) ? 0 : maxLen;
    }
};
