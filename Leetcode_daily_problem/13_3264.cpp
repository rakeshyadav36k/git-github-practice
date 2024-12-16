/**
 * You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.
 */

class Solution {
public:
    #define P pair<int, int> 
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            nums[idx] = multiplier*num;

            pq.push({multiplier * num, idx});
        }

        return nums;
    }
};