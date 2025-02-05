/**
 * You are given two strings s1 and s2 of equal length. 
 * A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
 */

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int i;
        for(i = 0; i < n; i++){
            if(s1[i] != s2[i]) break;
        }

        // we want to make s2 equal to s1 by swapping opn in s2
        for(int j = 0; j < n; j++){
            string temp = s2;
            swap(s2[i], s2[j]);
            if(s1 == s2) return true;
            s2 = temp;
        }

        return i == n ? true : false;
    }
};