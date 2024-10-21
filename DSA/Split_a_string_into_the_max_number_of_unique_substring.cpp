/**
 * Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string.
 However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.
 */

class Solution {
public:

    void solve(int i, string s,unordered_set<string> &st, int currCnt, int &maxCnt){
        if(i >= s.length()){
            maxCnt = max(currCnt, maxCnt);
            return;
        }

        for(int j = i; j < s.length(); j++){
            string sub = s.substr(i, j-i+1);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                solve(j+1, s, st, currCnt+1, maxCnt);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCnt = 0;

        int i = 0;
        solve(i, s, st, 0, maxCnt);

        return maxCnt;
    }
};