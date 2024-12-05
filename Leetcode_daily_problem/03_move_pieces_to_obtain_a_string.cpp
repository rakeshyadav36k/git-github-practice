/**
 * You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, 
and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.
 */



// ---------- Brute force- it gives TLE
class Solution {
public:
    bool solve(string &str, string &target, unordered_map<string, bool> &mp, int n){
        if(str == target) return true;

        if(mp.count(str)) return mp[str];

        for(int i = 0; i < n; i++){
            if(str[i] == 'L' && i > 0 && str[i-1] == '_'){
                swap(str[i], str[i-1]);
                if(solve(str, target, mp, n) == true){
                    return true;
                }
                swap(str[i], str[i-1]);
            }
            else if(str[i] == 'R' && i < n-1 && str[i+1] == '_'){
                swap(str[i], str[i+1]);
                if(solve(str, target, mp, n) == true){
                    return true;
                }
                swap(str[i], str[i+1]);
            }
        }
        return mp[str] = false;
    }

    bool canChange(string start, string target) {
        unordered_map<string, bool> mp;
        int n = start.size();
        return solve(start, target, mp, n);
    }
};