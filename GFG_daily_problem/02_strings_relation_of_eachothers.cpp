// You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

// Note: The characters in the strings are in lowercase.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// ---- 1st method
/*
class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        if (s1.size() != s2.size()) {
            return false;
        }

        string temp = s1 + s1;
        return (temp.find(s2) != string::npos);
    }
};

*/

// 2nd method

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    vector<int> compute(string &pat)
    {
        
        int n=pat.size();
        vector<int> lps(n,0);
        int i=0;
        int j=1;
        
        while(j<n)
        {
            if(pat[i]==pat[j])
            {
                lps[j++]=++i;
            }
            else
            {
             if(i!=0)
             {
                 i=lps[i-1];
             }
             else
             {
                 lps[j++]=0;
             }
                
            }
        }
        return lps;
        
        
    }
    
    bool areRotations(string &s1, string &s2) {
       if(s1.length()!=s2.length())
       return false;
       
        string txt=s1+s1;
        string pat=s2;
        
        int m=txt.length();
        int n=pat.length();
        int i=0;
        int j=0;
        vector<int> lps = compute(pat); 
        while(i<m)
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
             if(j==n)
            {
                return true;
            }
           else if(i<m && pat[j]!=txt[i])
           {
               if(j!=0)
               {
                   j=lps[j-1];
               }
               else
               i++;
           }
        }
        return false;
        
        
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends