//931. minimum falling path sum


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = 0 ; i < n ; i ++ ){
            dp[0][i]=matrix[0][i];
        }

        for(int i = 1; i < n ; i++){
            for(int j = 0; j < n; j++){
                
                int up = matrix[i][j] + dp[i-1][j];
                int dl = matrix[i][j];
                if(j>0){
                   dl += dp[i-1][j-1];
                }
                else dl+=1e9;
                int dr = matrix[i][j];
                if(j<n-1){
                     dr += dp[i-1][j+1];
                }
                else dr+=1e9;

                dp[i][j] = min(up,min(dr,dl));
            }
        }

        int minval = 1e9;
        for(int i = 0 ; i < n ; i++){
            minval = min ( minval, dp[n-1][i]);
        }

        return minval;

    }
};
