class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int element = INT_MAX;
        int max_profit = 0;
        int n = prices.size();
        for(int i = 0 ; i < n ; i ++){
            element = min(element,prices[i]);
            int profit = prices[i] - element;
            max_profit = max(max_profit,profit);
        }
        return max_profit;
    }
};