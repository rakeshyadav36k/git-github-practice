/**
 * You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. 
 * The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. 
 * You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, 
you cannot attend two events where one of them starts and the other ends at the same time. 
More specifically, if you attend an event with end time t, the next event must start at or after t + 1.
 */


// ------- sorting + binary search

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }
        
        int maxSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n - 1;
            int nextEventIndex = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextEventIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            if (nextEventIndex != -1) {
                maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
            }
            
            maxSum = max(maxSum, events[i][2]);
        }
        
        return maxSum;
    }
};





// ------------- sorting + greedy
class Solution {
public:
    using info=tuple<int, bool, int>;
    static int maxTwoEvents(vector<vector<int>>& events) {
        const int n=events.size();
        vector<info> time(n*2);
        for(int i=0; i<n; i++){
            int s=events[i][0], e=events[i][1], v=events[i][2];
            time[2*i]={s, 0, v};
            time[2*i+1]={e, 1, v};
        }
        sort(time.begin(), time.end());
        int ans=0, maxV=0, n2=n*2;
        for(auto& [t, isEnd, v]: time){
            if (isEnd) maxV=max(maxV, v);
            else ans=max(ans, maxV+v);
        }
        return ans;    
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();