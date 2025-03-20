/**
 * In daily share trading, a trader buys shares and sells them on the same day. 
 * If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

You are given an array prices[] representing stock prices throughout the day. 
Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
            vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
            
            for(int index=n-1;index>=0;index--)
            {
                for(int buy=0;buy<=1;buy++)
                {
                    for(int limit=1;limit<=2;limit++)
                    {
                        if(buy==1)
                        {
                            int buyit= -prices[index]+dp[index+1][0][limit];
                            int skip= 0+ dp[index+1][1][limit];
                            dp[index][buy][limit]=max(buyit,skip);
                        }
                        else
                        {
                            int sell=prices[index]+dp[index+1][1][limit-1];
                            int skip=0+dp[index+1][0][limit];
                            dp[index][buy][limit]=max(sell,skip);
                        }
                    }
                }
            }
        
        return dp[0][1][2];
        
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

