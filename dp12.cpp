//188. best time to buy and sell stock IV

class Solution {
public:
    int buying(int ind, int buy, int cap, vector<int>& prices,vector<vector<vector<int>>>& dp){
        
        int n = prices.size();
        if(ind == n || cap==0){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        int profit = 0 ;
        if(buy){
            profit  = max(-prices[ind] + buying(ind+1,0,cap,prices,dp), 0 + buying(ind+1,1,cap,prices,dp));
        }
        else{
            profit = max(prices[ind]+buying(ind+1,1,cap-1,prices,dp), 0+buying(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return buying(0,1,k,prices,dp);
    }
};
