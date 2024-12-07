/**
 * Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    // cconquer
    void merge(vector<int> &arr, int l, int mid, int r){
        vector<int> v1(arr.begin()+l, arr.begin()+mid+1);
        vector<int> v2(arr.begin()+mid+1, arr.begin()+r+1);
        
        int i = 0, j = 0, k = l;
        
        while(i < v1.size() && j < v2.size()){
            if(v1[i] <= v2[j]) arr[k++] = v1[i++];
            else{
                ans = ans + (v1.size() - i);
                arr[k++] = v2[j++];
            }
        }
        
        while(i < v1.size()){
            arr[k++] = v1[i++];
        }
        while(j < v2.size()){
            arr[k++] = v2[j++];
        }
    }
  
    // divide
    void divide(vector<int> &arr, int l, int r){
        if(l < r){
            int mid = (l + r) / 2;
            divide(arr, l, mid);
            divide(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
  
  
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        divide(arr, 0, arr.size()-1);
        
        return ans;
    }
};


int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

