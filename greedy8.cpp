//135. candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int,int>> pair(n);
        for(int i = 0 ; i< n ; i ++){
            pair[i] = {ratings[i],i};
        }
        sort(pair.begin(),pair.end());
        vector<int> candies(n,1);
        
        for(int i = 0 ; i < n ; i ++){
            int idx = pair[i].second;
            int curr = pair[i].first;
            if (idx > 0 && curr > ratings[idx - 1]) {
                candies[idx] = max(candies[idx], candies[idx - 1] + 1);
            }
            if (idx < n - 1 && curr > ratings[idx + 1]) {
                candies[idx] = max(candies[idx], candies[idx + 1] + 1);
            }
        }
        int total = 0;
        for (int c : candies) total += c;
        return total;
    }
};
