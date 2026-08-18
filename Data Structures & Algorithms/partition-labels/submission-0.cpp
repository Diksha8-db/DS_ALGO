class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        // INTUTION : We will take the character and put in one substring until all such char are in the string
        int n = s.length();

        // to track the last index of every character
        vector<int> lastIdx(26,0);
        for(int i = 0; i < n; i++){
            lastIdx[s[i]-'a'] = i;
        }

        // now start traversal 
        int st = 0, end = 0;
        for(int i = 0; i < n; i++){
            end = max(end, lastIdx[s[i]-'a']); // extend partition to cover this char

            // if we reached the end of current partition
            if(i == end){
                ans.push_back(end - st + 1);
                st = i + 1; // next partition starts here
            }
        }
        
        return ans;
    }
};
