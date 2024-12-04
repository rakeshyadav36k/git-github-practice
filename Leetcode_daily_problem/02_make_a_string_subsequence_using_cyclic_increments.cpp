/**
 * You are given two 0-indexed strings str1 and str2.

In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. 
That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.

Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.

Note: A subsequence of a string is a new string that is formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.
 */

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), i = 0;
        int m = str2.size(), j = 0;
        
        if(n < m) return false;
        
        while(i < n){
            if(j==m) return true;
            
            if(str1[i] != 'z' && (str1[i] == str2[j] || str1[i]+1 == str2[j])){
                i++;
                j++;
            }
            else if(str1[i] == 'z' && (str1[i] == str2[j] || 'a' == str2[j])){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==m) return true;
        return false;
    }
};