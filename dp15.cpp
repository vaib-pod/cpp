//322. coin change

class Solution {
public:
    int count(int ind, vector<int>& coins, int amount,vector<vector<int>> &dp){
        int n = coins.size();
        if(ind==n){
            if(amount%coins[n-1]==0) return amount/coins[n-1];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take = INT_MAX;
        int notTake = 0 + count(ind+1,coins, amount,dp);
        if(coins[ind]<=amount){
            take = 1 + count(ind, coins,amount-coins[ind],dp); 
        }
        return dp[ind][amount] = min(take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans =  count(0,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};
