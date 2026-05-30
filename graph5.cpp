// 1020. number of enclaves

class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>> &visited , int r, int c){
        int m = grid.size();
        int n = grid[0].size();

        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]!=1 || visited[r][c]){
            return;
        }
        visited[r][c] = 1;
        dfs(grid, visited, r-1 ,c );
        dfs(grid, visited, r ,c-1 );
        dfs(grid, visited, r ,c+1 );
        dfs(grid, visited, r+1 ,c );
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0 ; i< n ; i++){
            if(grid[0][i]==1){
                dfs(grid,visited,0,i);
            }
            if(grid[m-1][i]==1){
                dfs(grid,visited,m-1,i);
            }
        }
        for(int i = 0 ; i< m ; i++){
            if(grid[i][0]==1){
                dfs(grid,visited,i,0);
            }
            if(grid[i][n-1]==1){
                dfs(grid,visited,i,n-1);
            }
        }
        int count = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
