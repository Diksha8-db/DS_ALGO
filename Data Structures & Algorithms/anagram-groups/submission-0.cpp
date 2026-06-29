class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // store the freq of each char and use this fre as map to map all the string having same freq map
        map<vector<int>,vector<string>> anagMap;

        for(string s : strs){
            vector<int> charFreq(26,0);
            for(char ch : s){
                charFreq[ch-'a']++;
            }
            anagMap[charFreq].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto const&[val,str] : anagMap){
           ans.push_back(str);
        }

        return ans;
    }
};
