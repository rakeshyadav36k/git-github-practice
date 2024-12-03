/*
You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. 
Each space should be inserted before the character at the given index.

For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".
Return the modified string after the spaces have been added.
*/

// ------------ 1st Method  */
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int start_idx = 0;
        for(int i = 0; i < spaces.size(); i++){
            int len = spaces[i] - start_idx;
            res += s.substr(start_idx, len);
            res += " ";
            start_idx = spaces[i];
        }
        res += s.substr(start_idx);

        return res;
    }
};