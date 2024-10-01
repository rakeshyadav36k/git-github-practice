/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it can trap after raining.
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n); 
        leftMax[0] = height[0];
        for(int i = 1;i < n;i++){
            leftMax[i] = max(leftMax[i-1] , height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int i = n-2;i >= 0;i--){
            rightMax[i] = max(rightMax[i+1] , height[i]);
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans += min(leftMax[i] , rightMax[i]) - height[i];
        }
        return ans;

        //Using two pointer method
        // int left = 0;
        // int right = n-1;

        // int leftMax = 0;
        // int rightMax = 0;
        
        // int ans = 0;
        // while(left <= right){
        //     if(leftMax <= rightMax){
        //         // Add the difference between current value and left max at index left
        //         ans += max(0 , leftMax - height[left]);
        //         leftMax = max(leftMax , height[left]); // update the leftMax value
        //         left++; // move to next pointer
        //     }
        //     else{
        //         // Add the difference between current value and left max at index right
        //         ans += max(0 , rightMax - height[right]);
        //         rightMax = max(rightMax , height[right]);// update the rightMax value
        //         right--;// move to prev pointer
        //     }
        // }
        // return ans;
    }
};