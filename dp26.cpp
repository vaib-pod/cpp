//1043. partition array for maximum sum

class Solution {
public:
    int f(int ind, vector<int>& arr, int k,vector<int> &dp){
        int n = arr.size();
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxans = INT_MIN;
        for(int i = ind ; i < min(ind+k,n);i++){
            len++;
            maxi = max(maxi, arr[i]);
            int sum = len*maxi + f(i+1,arr,k,dp);
            maxans = max(maxans,sum);
        }
        return dp[ind] = maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,k,dp);
    }
};
