//518. coin change II

class Solution {
public:
    int count(int ind, vector<int>& coins, int amount,vector<vector<int>> &dp){
        int n = coins.size();
        if(ind==n-1){
            if(amount%coins[n-1]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take = 0;
        int notTake = count(ind+1,coins, amount,dp);
        if(coins[ind]<=amount){
            take = count(ind, coins,amount-coins[ind],dp); 
        }
        return dp[ind][amount] = take+notTake;

    }
    int change(int amount , vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans =  count(0,coins,amount,dp);
        return ans;
    }
};
