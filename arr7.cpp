//121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int element = INT_MAX;
        int max_profit = 0;
        int n = prices.size();
        for(int i = 0 ; i < n ; i ++){
            if(prices[i]<element){
                element = prices[i];
            }
            int profit = prices[i] - element;
            if(profit>max_profit){
                max_profit = profit;
            }
        }
        return max_profit;
    }
};
