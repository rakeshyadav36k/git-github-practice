/**
 * You are given an array of integers nums of size 3.

Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.

Note that the binary representation of any number does not contain leading zeros.
 */

class Solution {
public:
    string toBinary(int num) {
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }
    
    
    static bool cmp(int a, int b){
        Solution sol;
        string binA = sol.toBinary(a);
        string binB = sol.toBinary(b);
        return (binA + binB) > (binB + binA);
    }
    
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        
        string concatenatedBinary = "";
        for (int num : nums) {
            concatenatedBinary += toBinary(num);
        }
        
        int result = stoi(concatenatedBinary, 0, 2);
        
        return result;
    }
};