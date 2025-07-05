/**
 * Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.
 */

 class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int lucky = -1;

        for (auto& [key, value] : freq) {
            if (key == value) {
                lucky = max(lucky, key);
            }
        }

        return lucky;
    }
};