/**
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.
 */

// 1st method using stack
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;

        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                if(st.empty() || st.top() == ')')
                    st.push(s[i]);

                else if(!st.empty() && st.top() == '(')
                    st.pop();
            }

            else st.push(s[i]);
        }

        return st.size();
    }
};

// 2nd method

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (auto c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }
        return open + close;
    }
};