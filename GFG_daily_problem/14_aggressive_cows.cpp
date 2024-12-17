/**
 * You are given an array with unique elements of stalls[], which denote the position of a stall. 
 * You are also given an integer k which denotes the number of aggressive cows. 
 * Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.
 */


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isPossible(int mid, vector<int> &stalls, int k){
        int temp = stalls[0], cnt = 1;
        
        for(int i = 0; i < stalls.size(); i++){
            if(stalls[i] - temp >= mid){
                temp = stalls[i];
                cnt++;
            }
            
            if(cnt == k) return true;
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int diff_max = stalls[n-1] - stalls[0];
        int diff_min = 1;
        int ans = 0;
        
        while(diff_min <= diff_max){
            int mid = (diff_min + diff_max) / 2;
            
            if(isPossible(mid, stalls, k)){
                diff_min = mid + 1;
                ans = max(ans, mid);
            }
            else{
                diff_max = mid - 1;
            }
        }
        
        return ans;
    }
};


int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
