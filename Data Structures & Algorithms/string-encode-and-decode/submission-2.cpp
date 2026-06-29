class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        int len = 0;
        for(string str : strs){
            len = str.length();
            s += (to_string(len) + '#' + str);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        while(i < s.length()){
            int j = i;

            while(s[j] != '#') j++;

            // if we got the hash it means length of string we got
            int len = stoi(s.substr(i,j-i));

            string word = s.substr(j+1, len);
            ans.push_back(word);

            i = j + len + 1;
        }
        return ans;
    }
};
