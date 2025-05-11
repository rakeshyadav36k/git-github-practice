/**
 * Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 */

 // 1st - brute force
 class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < n - 2; i++) {
            // Check if the current element and the next two elements are all
            // odd
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};

// 2nd - counting
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutiveOdds = 0;

        // Loop through each element in the array
        for (int i = 0; i < arr.size(); i++) {
            // Increment the counter if the number is odd,
            // else reset the counter
            if (arr[i] % 2 == 1) {
                consecutiveOdds++;
            } else {
                consecutiveOdds = 0;
            }

            // Check if there are three consecutive odd numbers
            if (consecutiveOdds == 3) {
                return true;
            }
        }

        return false;
    }
};