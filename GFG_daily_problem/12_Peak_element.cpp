/**
 * Given an array arr[] where no two adjacent elements are same, find the index of a peak element. 
 * An element is considered to be a peak if it is greater than its adjacent elements (if they exist). 
 * If there are multiple peak elements, return index of any one of them. 
 * The output will be "true" if the index returned by your function is correct; otherwise, 
 * it will be "false".

Note: Consider the element before the first element and the element after the last element to be negative infinity.
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // int peakElement(vector<int> &arr) {
    //     int n = arr.size();
    //     if (n == 1)
    //         return 0;

    //     for (int i = 0; i < n; i++)
    //     {      
    //         if (i == 0)
    //         {
    //             if (arr[i] >= arr[i + 1])
    //                 return i;
    //         }
    //         else if (i == n - 1)
    //         {
    //             if (arr[i] >= arr[i - 1])
    //                 return i;
    //         }
    //         else
    //         {
    //             if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
    //                 return i;
    //         }
    //     }

    //     // If no peak element is found, return -1.
    //     return -1;
    // }

    int peakElement(vector<int> &arr) {
        int s=0, e= arr.size()-1;
        while(s < e){
            int mid = s+(e-s)/2;
            if(arr[mid] > arr[mid+1]){
                //You are in desc part of the array
                e = mid;
            }
            else{
                //You are in asc part
                s = mid+1;
            }
        }
        return s;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;

            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

