class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double sum = 0;
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int k = 0;
        for(int i = 0 ; i < prices.size();i++){
            if(k<discounts.size()){
                double current = (prices[i]*(100-discounts[k]))/100.00;
                sum+=current;
                k++;
            }
            else{
                sum+=prices[i];
            }
        }
        return sum;
    }
};