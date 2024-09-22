#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lps(string str) {
        int n = str.size();
        vector<int> ans(n,0);
        int i = 0;
        int j = 1;
        
        while(j != n){
             // case 1 : Both are same
             if(str[i] == str[j]){
                ans[j] = i + 1;
                i++;
                j++;
             }
               // case 2 : Both are not same
              else{
                  // case 1: i == 0
                  if(i ==0){
                      ans[j] = 0;
                      j++;
                  }
                  //case 2 : i!=0
                  else{
                      i = ans[i - 1];
                  }
              }
        }
        return ans.back();
    }
};

int main(){
    int t;
    cin >> t;

    while(--t){
        string str;
        cin >> str;

        Solution obj;
        cout << obj.lps(str) << endl;
    }

    return 0;
}