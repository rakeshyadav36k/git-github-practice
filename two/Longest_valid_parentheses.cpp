/*
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.
A parenthesis string is valid if:
->For every opening parenthesis, there is a closing parenthesis.
->Opening parenthesis must be closed in the correct order.

 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(string& str) {
        int n = str.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty() && str[st.top()] == '('){
                    st.pop();
                    int first = st.empty() ? -1 : st.top();
                    ans = max(ans, i-first);
                }
                else{
                    st.push(i);
                }
            }
        }
        
        return ans;
    }
};


int main(){
    string s;
    cin >> s;

    Solution obj;
    cout << obj.maxLength(s) <<endl;
}