/**
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
In one operation:
1. choose an index i such that 0 <= i < nums.length,
2. increase your score by nums[i], and
3. replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.
 */
 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        long long ans = 0;
        while(k--){
            int topEle = pq.top();
            pq.pop();

            ans += topEle;

            pq.push(ceil(topEle / 3.0));
        }

        return ans;
    }
};

int main (){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }

        int k;
        cin >> k;

        Solution ob;
         cout << ob.maxKelements(vec, k) << endl;
    }

    return 0;
}