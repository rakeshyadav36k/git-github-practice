/**
 * You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order
 */

class Solution {
public:
    vector<int> count(string s){
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        return freq;
    }

    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> bMax(26, 0);
        for(auto b : B){
            vector<int> bCount = count(b);
            for(int i = 0; i < 26; i++){
                bMax[i] = max(bMax[i], bCount[i]);  
            }
        }

        vector<string> ans; 
        for(string a : A){
            bool isContinue = false;
            vector<int> aCount = count(a);
            for(int i = 0; i < 26; i++){
                if(aCount[i] < bMax[i]){
                    isContinue = true;
                    continue;
                }
            }
            if(isContinue) continue;

            ans.push_back(a);
        }

        return ans;
    }
};