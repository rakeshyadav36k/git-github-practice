/**
 * You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

All elements in the subarray are unique.
The sum of the elements in the subarray is maximized.
Return the maximum sum of such a subarray.
 */
int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> seen;
    int max_sum = 0, current_sum = 0, left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        while (seen.count(nums[right])) {
            seen.erase(nums[left]);
            current_sum -= nums[left];
            left++;
        }
        seen.insert(nums[right]);
        current_sum += nums[right];
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}
// Example usage:
// vector<int> nums = {4,2,4,5,6};
// int result = maximumUniqueSubarray(nums);
// cout << result << endl; // Output: 17 (subarray [5,6] gives the maximum sum)
// vector<int> nums2 = {1,2,3,4};           
// int result2 = maximumUniqueSubarray(nums2);
// cout << result2 << endl; // Output: 10 (subarray [1,