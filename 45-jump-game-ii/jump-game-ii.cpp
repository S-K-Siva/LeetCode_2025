class Solution {
public:

    int helper(int ind,int n, vector<int>& nums,vector<int>& dp){
        if(ind == n-1) return 0;
        if(ind >=n) return 1e9;

        if(dp[ind] != -1) return dp[ind];

        int jumps = 1e9;

        for(int i = 1;i<=nums[ind];i++){
            jumps = min(jumps,1 + helper(ind+i,n,nums,dp));
        }
        return dp[ind] = jumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = 0;
        return helper(0,n,nums,dp);
    }
};