class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0); // track the occurrence in string s2
        vector<int> freq2(26,0); // track the occurrence in string s1

        // edge case
        if(s1.length() > s2.length()) return false;

        for(char ch : s1)
            freq1[ch-'a']++;
        
        int i = 0;
        int n = s2.length();
        for(int j = 0; j < n; j++){
            // increement the freq of current element
            freq2[s2[j]-'a']++;

            // take the window to fixed size of s1.length()
            while((j-i+1) > s1.length()){
                // skrink the window
                freq2[s2[i]-'a']--;
                i++;
            }

            // if anytime freq2 is equal to freq1 return true
            if(freq1 == freq2) return true;
        }

        return false;
    }
};
