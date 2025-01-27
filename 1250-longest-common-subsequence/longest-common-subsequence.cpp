class Solution {
public:

    // Recursion
    // int solve(string s1, string s2, int m, int n){
    //     if(m == 0 || n == 0) return 0;

    //     if(s1[m-1] == s2[n-1]) return 1 + solve(s1,s2,m-1,n-1);
    //     return max(solve(s1,s2,m-1,n),solve(s1,s2,m,n-1));
    // }

    // memo
    // int solve(string s1, string s2, int m, int n,vector<vector<int>>& dp){
    //     if(m == 0 || n == 0) return 0;
    //     if(dp[m][n] != 0) return dp[m][n];

    //     if(s1[m-1] == s2[n-1]) return dp[m][n] = 1 + solve(s1,s2,m-1,n-1,dp);
    //     return dp[m][n] = max(solve(s1,s2,m-1,n,dp),solve(s1,s2,m,n-1,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // recursion
        // return solve(text1,text2,m,n)
        // memo
        // solve(text1,text2,m,n,dp);
        // return dp[m][n];

        // bottom-up
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};