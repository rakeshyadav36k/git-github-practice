/**
 * Given two sorted arrays a[] and b[] and an element k, 
 * the task is to find the element that would be at the kth position of the combined sorted array.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            k--;
            if(a[i] < b[j]){
                if(k == 0) return a[i];
                i++;
            }
            else{
                if(k == 0) return b[j];
                j++;
            }
        }
        while(i < a.size()){
            k--;
            if(k == 0) return a[i];
            i++;
        }
        while(j < b.size()){
            k--;
            if(k == 0) return b[j];
            j++;
        }
        
        return -1;
        
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
