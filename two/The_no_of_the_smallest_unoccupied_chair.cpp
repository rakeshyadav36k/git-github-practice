/**
 * There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity.
  When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. 
All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.
 */

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Create a list of arrivals with friend index for tracking
        std::vector<std::pair<int, int>> arrivals;
        for (int i = 0; i < n; ++i) {
            arrivals.push_back({times[i][0], i});
        }
        
        // Sort friends based on their arrival time
        std::sort(arrivals.begin(), arrivals.end());
        
        // Min-Heap to track available chairs
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // All chairs start as available
        }

        // Priority queue to track when chairs are freed
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> leavingQueue;
        
        // Iterate through each friend based on arrival
        for (auto& arrival : arrivals) {
            int arrivalTime = arrival.first;
            int friendIndex = arrival.second;
            
            // Free chairs that are vacated before the current arrival time
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrivalTime) {
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }
            
            // Assign the smallest available chair
            int chair = availableChairs.top();
            availableChairs.pop();
            
            // If this is the target friend, return their chair number
            if (friendIndex == targetFriend) {
                return chair;
            }
            
            // Mark the chair as being used until the friend's leave time
            leavingQueue.push({times[friendIndex][1], chair});
        }
        
        return -1; // Should never reach here
    }
};