/**
 * Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
Note: Each element is res[] lies inside the 32-bit integer range.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int>v;
        int ans=1;
        int zc=0;
        for(auto ele : arr){
            if(ele!=0)
            ans*=ele;
            else
            zc++;
        }
        for(auto ele : arr){
            if(zc==0){
                v.push_back(ans/ele);
            }
            else if(zc==1){
                if(ele==0)
                v.push_back(ans);
                else
                v.push_back(0);
            }
            else{
                v.push_back(0);
            }
        }
        return v;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

