/**
 * Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.
 */


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int cnt = 0, n = citations.size();
        
        int i = n-1;
        while(i >= 0 && citations[i] > cnt){
            cnt++;
            i--;
        }
        
        return cnt;
    }
};



int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}
