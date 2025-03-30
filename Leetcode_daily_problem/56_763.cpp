/**
 * You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.
 */

 // 1st- two pointer
 class Solution {
    public:
        vector<int> partitionLabels(string s) {
            // Stores the last index of each character in 's'
            vector<int> lastOccurrence(26, 0);
            for (int i = 0; i < s.size(); ++i) {
                lastOccurrence[s[i] - 'a'] = i;
            }
    
            int partitionEnd = 0, partitionStart = 0;
            vector<int> partitionSizes;
            for (int i = 0; i < s.size(); ++i) {
                partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
                // End of the current partition
                if (i == partitionEnd) {
                    partitionSizes.push_back(i - partitionStart + 1);
                    partitionStart = i + 1;
                }
            }
            return partitionSizes;
        }
    };