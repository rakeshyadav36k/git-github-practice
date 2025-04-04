/**
 * Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string> > result;

        // hash map to maintain groups of anagrams
        unordered_map<string, vector<string> > mp;

        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];

            // sort each string
            sort(s.begin(), s.end());

            // add original string to corresponding sorted string in hash map
            mp[s].push_back(arr[i]);
        }
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
            result.push_back(itr->second);

        return result;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

