//gfg. sunset sum problem 

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
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(0,arr,sum,dp);
    }
};
