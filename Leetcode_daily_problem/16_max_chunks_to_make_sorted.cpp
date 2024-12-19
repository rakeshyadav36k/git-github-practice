/**
 * 769
 * You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk.
 After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
 */

// ----------- using prefix sum

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        int sortedPrefixSum = 0;  // prefix sum of sorted array -> 0 1 2 3 4 5 6 7 ......
        int prefixSum = 0;
        int cnt = 0;   // no of chunks
        for(int i = 0; i < n; i++){    
            sortedPrefixSum += i;

            prefixSum += arr[i];

            if(prefixSum == sortedPrefixSum){
                cnt++;
            }
        }

        return cnt;
    }
};

//--------------- using "Max Element"
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, maxElement = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update maxElement
            maxElement = max(maxElement, arr[i]);

            if (maxElement == i) {
                // All values in range [0, i] belong to the prefix arr[0:i];
                // a new chunk can be formed
                chunks++;
            }
        }

        return chunks;
    }
};