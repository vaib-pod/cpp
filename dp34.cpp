//494. target sum

class Solution {
public:
    int countDiff(int ind, int k, vector<int>& nums, vector<vector<int>>& dp){
        if(ind>=nums.size()){
            if(k==0) return 1;
            return 0;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int notTake = countDiff(ind+1,k,nums,dp);
        int take = 0;
        if(nums[ind]<=k){
            take = countDiff(ind+1,k-nums[ind],nums,dp);
        }
        return dp[ind][k] =  take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ;  i< nums.size();i++){
            sum+=nums[i];
        }
        
        if ((sum + target) < 0 || (sum + target) % 2 != 0) {
            return 0;
        }
        int k = (sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return countDiff(0,k, nums,dp);
    }
};
