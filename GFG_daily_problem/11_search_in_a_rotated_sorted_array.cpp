/**
 * Given a sorted and rotated array arr[] of distinct elements, 
 * the task is to find the index of a target key. Return -1 if the key is not found.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low=0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] == key) return mid;
            
            
         
            if(arr[mid] >= arr[low]) { // if it is true it means left half is sorted

                // Checking whether key lies beteen low and mid or not
                if(key>=arr[low] && key<=arr[mid]) high = mid-1;
                else low = mid+1;
            } 

            else { // if it is true it means right half is sorted

                // Checking whether key lies between mid and high or not
                if(key>=arr[mid] && key<=arr[high]) low = mid+1;
                else high = mid-1;
            }
        }
        
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
