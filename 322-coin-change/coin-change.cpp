class Solution {
public:
    int solve(vector<int> coins, int target,int n,vector<int>& dp){
        if(target == 0) return 0;
        if(target < 0) return INT_MAX;
        if(dp[target] != -1) return dp[target];
        int minCoins = INT_MAX;
        for(int i = 0;i<n;i++){
            if(target - coins[i] >= 0){
                int value = solve(coins, target-coins[i],n,dp);
                if(value != INT_MAX){
                    minCoins = min(minCoins, value + 1);
                }
            }
        }
        return dp[target] = minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return amount;
        vector<int> dp(amount+1,-1);
        int result = solve(coins, amount, coins.size(),dp);
        
        return result == INT_MAX ? -1 : result;

    }
};