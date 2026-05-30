//200. number of islands
class Solution {
public:
    void dfs(vector<vector<char>>& grid , int r , int c,vector<vector<int>> &visited){
        int m = grid.size();
        int n = grid[0].size();

        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]=='0' || visited[r][c]){
            return;
        }
        visited[r][c] = 1;
        dfs(grid, r-1 ,c , visited);
        dfs(grid, r+1 ,c , visited);
        dfs(grid, r ,c-1 , visited);
        dfs(grid, r ,c+1 , visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    islands++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return islands;
    }
};
