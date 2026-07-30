class Solution {
public:
    bool isPalindrome(string s) {
        // find the string without the spaces and special characters
        string ans = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(isalnum(s[i]) && s[i] != ' '){
                ans += tolower(s[i]);
            }
            else continue;
        }

        int i = 0;
        int j = ans.length() - 1;
        cout << ans << endl;

        while(i < j){
            if(ans[i] != ans[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
