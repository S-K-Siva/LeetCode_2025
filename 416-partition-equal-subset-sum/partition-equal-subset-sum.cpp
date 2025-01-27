class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalWeight = accumulate(nums.begin(),nums.end(),0);
        if(totalWeight % 2 == 1) return false;

        int targetWeight = totalWeight / 2;
        
        vector<bool> dp(targetWeight + 1, false);
        dp[0] = true;

        for(int i = 0;i<nums.size();i++){
            for(int j = targetWeight;j>=nums[i];j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[targetWeight];
    }
};