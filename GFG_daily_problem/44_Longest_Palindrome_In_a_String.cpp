/**
 * Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.
 */

 class Solution {
    public:
    
    string longestPalin (string s) {
          int n=s.size();
          int start=0,end=0,maxl=1;
          
          //odd length
          for(int i=0;i<n;i++)
          {
              int l=i,r=i;
              while(l>=0 && r<n)
              {
                  if(s[l]!=s[r])
                  {
                      break;
                  }
                  l--;
                  r++;
              }
              int len=r-l-1;
              if(len>maxl)
              {
                  maxl=len;
                  start=l+1;
                  end=r-1;
              }
          }
          
          //even length
          for(int i=0;i<n;i++)
          {
              int l=i,r=i+1;
              while(l>=0 && r<n)
              {
                  if(s[l]!=s[r])
                  {
                      break;
                  }
                  l--;
                  r++;
              }
              int len=r-l-1;
              if(len>maxl)
              {
                  maxl=len;
                  start=l+1;
                  end=r-1;
              }
          }
          
          return s.substr(start,maxl);
      }
  };