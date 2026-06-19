//416. partition equal subset sum 

class Solution {
public:
    bool f(int ind, vector<int>& arr, int sum,vector<vector<int>>& dp){
        int n = arr.size();
        if(sum==0) return true;
        if(ind==n){
            return false;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool notTake = f(ind+1,arr,sum,dp);
        bool take = false;
        if(sum>=arr[ind]){
            take = f(ind+1,arr,sum-arr[ind],dp);
        }
        return dp[ind][sum] = take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i< n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum = sum/2; 
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(0,nums,sum,dp);
    }
};
