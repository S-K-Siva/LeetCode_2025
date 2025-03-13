class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int track_profit = 0;
        int n = prices.size();
        for(int i = 1;i<n;i++){
            int difference = prices[i] - prices[i-1];
            track_profit = max(0,track_profit+difference);
            profit = max(profit,track_profit);
        }

        return profit;
    }
};