/**
 * You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
 */

// 1st method - using queue
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            queue<char> blockQueue;
            int numWhites = 0;
    
            // Initiate queue with first k values
            while (blockQueue.size() < k) {
                char currentChar = blocks[blockQueue.size()];
                if (currentChar == 'W') numWhites++;
                blockQueue.push(currentChar);
            }
    
            // Set initial minimum
            int numRecolors = numWhites;
            for (int i = k; i < blocks.size(); i++) {
                // Remove top element from queue and update current number of white
                // blocks
                if (blockQueue.front() == 'W') numWhites--;
                blockQueue.pop();
    
                // Add current element to queue and update current number of white
                // blocks
                if (blocks[i] == 'W') numWhites++;
                blockQueue.push(blocks[i]);
    
                // Update minimum
                numRecolors = min(numRecolors, numWhites);
            }
            return numRecolors;
        }
    };