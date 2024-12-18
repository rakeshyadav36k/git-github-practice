/**
 * You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. 
If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, 
considering the special discount.
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> result = prices;

        for(int i = 0; i < n; i++){

            while(!st.empty() && prices[i] <= prices[st.top()]){
                result[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }

            st.push(i);
        }

        return result;
    }
};