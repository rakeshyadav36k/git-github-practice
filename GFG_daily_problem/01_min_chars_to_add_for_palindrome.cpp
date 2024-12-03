/**
 * Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.
 */

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string rev = s; reverse(rev.begin(), rev.end());
        string concat = s + "#" + rev;
        int n = concat.size(), l = 0;
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            while (l > 0 && concat[i] != concat[l]) l = lps[l - 1];
            if (concat[i] == concat[l]) l++;
            lps[i] = l;
        }
        return s.size() - lps[n - 1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends