/**
 * You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 
 */

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n), frequency(n + 1, 0);
        int commonCount = 0;

        // Iterate through the elements of both arrays
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Increment frequency of current elements in A and B
            // Check if the element in A has appeared before (common in prefix)
            if (++frequency[A[currentIndex]] == 2) ++commonCount;

            // Check if the element in B has appeared before (common in prefix)
            if (++frequency[B[currentIndex]] == 2) ++commonCount;

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
};