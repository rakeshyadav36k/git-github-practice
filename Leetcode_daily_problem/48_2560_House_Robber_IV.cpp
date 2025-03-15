/**
 * There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
 */

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        // Store the maximum nums value in maxReward.
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end()),
            totalHouses = nums.size();

        // Use binary search to find the minimum reward possible.
        while (minReward < maxReward)
        {
            int midReward = (minReward + maxReward) / 2;
            int possibleThefts = 0;

            for (int index = 0; index < totalHouses; ++index)
            {
                if (nums[index] <= midReward)
                {
                    possibleThefts += 1;
                    index++; // Skip the next house to maintain the
                             // non-adjacent condition
                }
            }

            if (possibleThefts >= k)
                maxReward = midReward;
            else
                minReward = midReward + 1;
        }

        return minReward;
    }
};