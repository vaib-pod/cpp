class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 0;
        int minval = INT_MAX;
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i = 1 ; i*i<=n;i++){
            int result = 1+solve(n-i*i,dp);
            minval = min(minval, result);
        }
        return dp[n] = minval;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};