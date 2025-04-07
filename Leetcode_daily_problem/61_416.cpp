/**
 * Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
 */

 // 1st- dp using recursion (top-down method)
 class Solution {
    public:
        bool f(int ind,int target,vector<int> nums,vector<vector<int>> &dp){
            if(target==0) return true;
            if(ind==0) return (nums[0]==target);
    
            if(dp[ind][target] != -1) return dp[ind][target];
            bool Take = false;
            if(nums[ind] <= target){
                Take = f(ind-1,target-nums[ind],nums,dp);
            }
            bool notTake = f(ind-1,target,nums,dp);
    
            return dp[ind][target] = Take || notTake;
        }
    
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
    
            int totalSum = 0;
            for(auto it : nums){
                totalSum += it;
            }
            vector<vector<int>> dp(n,vector<int>(10000,-1));
            // if total sum is odd then it can't be partition into equal parts;
            if(totalSum % 2 != 0) return false;  
            else return f(n-1,totalSum/2,nums,dp);
        }
    };

// 2nd - bottom-up approach
    class Solution {
        public:
                
            bool canPartition(vector<int>& nums) {
                int n = nums.size();
        
                int totalSum = 0;
                for(auto it : nums){
                    totalSum += it;
                }
                // if total sum is odd then it can't be partition into equal parts;
                if(totalSum % 2 != 0) return false;  
 
        
                vector<vector<bool>> dp(n,vector<bool>(10000,0));
                for(int i=0;i<n;i++){
                    dp[i][0] = true;
                }
                dp[0][nums[0]] = true;
        
                for(int ind=1;ind<n;ind++){
                    for(int target=1;target<=totalSum/2;target++){
                        bool Take = false;
                        if(nums[ind] <= target){
                            Take = dp[ind-1][target-nums[ind]];
                        }
                        bool notTake = dp[ind-1][target];
        
                        dp[ind][target] = Take || notTake;
                    }
                }
                return dp[n-1][totalSum/2];
            }
        };