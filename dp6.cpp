//64. minimum path sum

class Solution {
private:
    int paths(int m, int n , vector<vector<int>> &matrix, vector<vector<int>> &dp){
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j ++){
                
                if(i==0 && j==0){
                    dp[0][0]=matrix[i][j];
                    continue;
                } 
            
                    int up = matrix[i][j];
                    int left = matrix[i][j];

                    if(i>0){
                        up += dp[i-1][j];
                    }
                    else up += 1e9;
                    if(j>0){
                        left += dp[i][j-1];
                    }
                    else left += 1e9;
                    dp[i][j] = min(left,up);
                
            }

        }
        return dp[m-1][n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        return paths(m,n,grid,dp);
    }
};
