/**
 * A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.
 */
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string res = "";
        for(int i = 0; i < n; i++){
            if(i >= 2 && (s[i-1] == s[i] && s[i-2] == s[i])){
                continue;
            }
            else res += s[i];
        }
        return res;
    }
};
// Example usage:
// Solution sol;        
// string result = sol.makeFancyString("leeetcode");
// cout << result; // Output: "leetcode"    

// string result2 = sol.makeFancyString("aaabaaaa");