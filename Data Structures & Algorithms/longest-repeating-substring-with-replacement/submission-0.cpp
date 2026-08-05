class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLength = INT_MIN;

        int i = 0;
        int maxFreq = 0;
        vector<int> freq(26,0);
        for(int j = 0; j < n; j++){
            // add the current element to the map
            freq[s[j]-'A']++;
            // now check the max element value and the value of character to be replaced
            maxFreq = max(maxFreq, freq[s[j]-'A']);

            // if the no of replacement is equal to the value of k, it is a potential answer
            if(((j-i+1)-maxFreq) <= k) maxLength = max(maxLength, j-i+1);

            // if the no of replacement is greater than the value of k, we need to increment the value of i to make it a valid window
            else{
                freq[s[i]-'A']--;
                i++;
            }
            maxLength = max(maxLength, j-i+1);
        }

        return maxLength;
    }
};
