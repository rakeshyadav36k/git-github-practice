/**
 * You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
All the split words are put into a box.
Find the lexicographically largest string from the box after all the rounds are finished.

A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
If the first min(a.length, b.length) characters do not differ, then the shorter string is the lexicographically smaller one.
 */

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        int largestString = n - (numFriends - 1); // distribute (numFriends - 1) friends with single string and 
                                                //remaining 1 student will have the largest string;
        string res = "";
        for(int i = 0; i < n ; i++){
            string s = word.substr(i, largestString);
            res = max(res, s);
        }
        return res;
    }
};