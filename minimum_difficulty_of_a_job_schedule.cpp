class Solution {
public:
    int solve(int ind , vector<int>& jobDifficulty, int day,vector<vector<int>> &dp){
        int n = jobDifficulty.size();
        if(day==1){
            int maxval = 0;
            for(int i = ind; i < n;i++){
                maxval = max(maxval , jobDifficulty[i]);
            }
            return maxval;
        }
        if(dp[ind][day]!=-1){
            return dp[ind][day];
        }
        int ans = 10000;
        int maxD = jobDifficulty[ind];
        for(int i = ind ; i<=n-day;i++){
            maxD = max(maxD,jobDifficulty[i]);
            int current = maxD + solve(i+1,jobDifficulty,day-1,dp);
            ans = min(ans,current);
        }
        return dp[ind][day] = ans;

        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return solve(0,jobDifficulty,d,dp);

    }
};