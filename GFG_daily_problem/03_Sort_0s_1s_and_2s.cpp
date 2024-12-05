/**
 * Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
 */


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    void fill(vector<int> &arr, int &i, int val, int cnt) {
        while(cnt--) {
            arr[i++] = val;
        }
    }
    void sort012(vector<int>& arr) {
        int zeros = 0, ones = 0, twos = 0;
        for(int it: arr) {
            if(it == 0)
                zeros++;
            else if(it == 1)
                ones++;
            else 
                twos++;
        }
        
        int i = 0;
        
        fill(arr, i, 0, zeros);
        fill(arr, i, 1, ones);
        fill(arr, i, 2, twos);
    }
};


int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

