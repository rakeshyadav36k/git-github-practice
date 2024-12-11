/**
 * Given two sorted arrays a[] and b[] of size n and m respectively, 
 * the task is to merge them in sorted order without using any extra space. 
 * Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int idx = a.size() -1;
        int jdx = 0;
        
        while (idx >= 0 && jdx < b.size() ) {
            if (a.at(idx) > b.at(jdx)) {
                swap(a.at(idx), b.at(jdx));
            }
            idx--;
            jdx++;

        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
