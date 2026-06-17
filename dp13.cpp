//309. best time to buy and sell stocks with cooldown

class Solution {
public:
    int buying(int ind, int buy, vector<int>& prices,vector<vector<int>> &dp){
        
        int n = prices.size();
        if(ind >= n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit = 0 ;
        if(buy){
            profit  = max(-prices[ind] + buying(ind+1,0,prices,dp), 0 + buying(ind+1,1,prices,dp));
        }
        else{
            profit = max(prices[ind]+buying(ind+2,1,prices,dp), 0+buying(ind+1,0,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return buying(0,1,prices,dp);
    }
};
