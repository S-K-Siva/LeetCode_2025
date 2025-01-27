class Solution {
public:
    // Recursion
    // void solve(vector<int>& nums, int index, int cnt, int& maxi,int prev){
    //     if(index >= nums.size()){
    //         maxi = max(maxi, cnt);
    //         return;
    //     }

    //     if(prev == INT_MIN || nums[index] > prev){
    //         solve(nums,index+1,cnt+1,maxi,nums[index]);
    //     }
    //     solve(nums,index+1,cnt,maxi,prev);
    // }

    //memo
    // int solve(vector<int>& nums, int index,int prevIndex,
    // vector<vector<int>>& dp){
    //     if(index >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[index][prevIndex + 1] != -1){
    //         return dp[index][prevIndex + 1];
    //     }
    //     int length = solve(nums,index+1,prevIndex,dp);
    //     if(prevIndex == -1 || nums[index] > nums[prevIndex]){
    //         length = max(length,1 + solve(nums,index+1,index,dp));
    //     }
    //     return dp[index][prevIndex + 1] = length;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();


        
        // // recursion
        // int maxi = INT_MIN;
        // int cnt = 0;
        // int prev = INT_MIN;
        // solve(nums,0,cnt,maxi,prev);
        // return maxi == INT_MIN ? 1 : maxi;

        // // memo
        // int prev = -1;
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        // return solve(nums,0,prev,dp);

        // bottom-up
        vector<int> dp(n,1);
        int res = INT_MIN;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res == INT_MIN ?  1 : res;
    }
};