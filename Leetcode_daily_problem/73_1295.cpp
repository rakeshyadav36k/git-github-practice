/**
 * Given an array nums of integers, return how many of them contain an even number of digits.
 */

 // 1st - Extract digits
 class Solution {
    public:
        // Helper function to check if the number of digits is even
        bool hasEvenDigits(int num) {
            int digitCount = 0;
            while (num) {
                digitCount++;
                num /= 10;
            }
            return (digitCount & 1) == 0;
        }
    
        int findNumbers(vector<int>& nums) {
            // Counter to count the number of even digit integers
            int evenDigitCount = 0;
    
            for (int num : nums) {
                if (hasEvenDigits(num))
                    evenDigitCount++;
            }
    
            return evenDigitCount;
        }
    };

// 2nd - convert to string
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            // Counter to count the number of even digit integers
            int evenDigitCount = 0;
    
            for (int num : nums) {
                // Convert num to string and find its length
                int length = to_string(num).length();
                if (length % 2 == 0)
                    evenDigitCount++;
            }
    
            return evenDigitCount;
        }
    };
