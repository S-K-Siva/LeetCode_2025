class Solution {
public:
    // recursion
    // bool solve(vector<int>& nums, int index, int target){
    //     if(target == 0) return true;
    //     if(index >= nums.size() || index < 0) return false;

    //     bool take =  solve(nums,index+1,target-nums[index]);
    //     bool notTake = solve(nums,index+1,target);

    //     return take || notTake;
    // }
    // memo
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index >= nums.size() || target < 0) return false;

        if (dp[index][target] != -1) return dp[index][target];

        
        bool take = solve(nums, index + 1, target - nums[index], dp);
        
        bool notTake = solve(nums, index + 1, target, dp);

        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalWeight = accumulate(nums.begin(),nums.end(),0);
        if(totalWeight % 2 == 1) return false;

        int targetWeight = totalWeight / 2;
        // recursion
        // return solve(nums,0,targetWeight);

        // memo
        vector<vector<int>> dp(nums.size(), vector<int>(targetWeight + 1, -1));
        
        return solve(nums, 0, targetWeight, dp);
        // // bottom-up
        // vector<bool> dp(targetWeight + 1, false);
        // dp[0] = true;

        // for(int i = 0;i<nums.size();i++){
        //     for(int j = targetWeight;j>=nums[i];j--){
        //         dp[j] = dp[j] || dp[j-nums[i]];
        //     }
        // }

        // return dp[targetWeight];
    }
};