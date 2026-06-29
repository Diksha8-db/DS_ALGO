class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charMap(26,0);

        for(char ch : s){
            charMap[ch-'a']++;
        }

        for(char ch : t){
            charMap[ch-'a']--;
        }

        for(int i : charMap){
            if(i != 0) return false;
        }
        return true;
    }
};
