class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxi = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0 ; i < m;i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j]==1){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }
                    else dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                else if(mat[i][j]==0){
                    dp[i][j]=0;
                }
                maxi = max(maxi,dp[i][j]);
            }
        }
        for (int k = maxi; k >= 1; --k) {
            int min_r = m, max_r = -1;
            int min_c = n, max_c = -1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] >= k) {
                        min_r = min(min_r, i);
                        max_r = max(max_r, i);
                        min_c = min(min_c, j);
                        max_c = max(max_c, j);
                    }
                }
            }
            if (max_r != -1) { 
                if ((max_r - min_r) >= k || (max_c - min_c) >= k) {
                    return k * k; 
                }
            }
        }
        return 0;
    }
};