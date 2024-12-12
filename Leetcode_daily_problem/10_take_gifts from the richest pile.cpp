/**
 * You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.
 */


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        long long ans = 0;

        // Adding all the elements in sum and heap (priority queue).
        for (int i : gifts) {
            q.push(i);
            ans += i;
        }
       // This loop will run k times.
        while (k--) {
            int v = q.top();

            // Subtracting the values of the elements from sum whose 
            // square root we are going to consider in our results
            // and adding the square root simultaneously.
            ans -= (v - sqrt(v));

            // Removing the number from the priority queue.
            q.pop();
            // Adding the square root in the priority queue.
            q.push(sqrt(v));
        }
        return ans;
    }
};