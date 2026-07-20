class Solution {
public:
    int solve(int ind, vector<vector<int>> &jobs,vector<int> & dp){
        int n = jobs.size();
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int notTake = 0 + solve(ind+1, jobs,dp);
        int take = 0;
        int nextInd = n;
        int low = ind+1;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(jobs[ind][1]<=jobs[mid][0]){
                high = mid-1;
                nextInd = mid;
            }
            else{
                low=mid+1;
            }
        }
        take = jobs[ind][2] + solve(nextInd, jobs,dp);
        return dp[ind] = max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n,vector<int>(3));
        for(int i = 0 ; i < n ; i ++){
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(n, -1);
        return solve(0,jobs,dp);
    }
};