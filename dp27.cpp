//gfg. matrix chain multiply

class Solution {
  public:
    int f(int i,int j,vector<int> &arr, vector<vector<int>>& dp){
        int n = arr.size();
        if(i==j) return 0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k = i; k < j;k++){
            int steps = arr[k]*arr[j]*arr[i-1] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
            mini = min (mini,steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
    }
};
