//994. rotting oranges


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countfresh = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j] =2;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }

        int tmax = 0 ;
        vector<int> drow = {-1,0,+1,0};
        vector<int> dcol = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tmax = max(tmax,t);
            q.pop();
            for(int i = 0 ; i < 4 ; i ++){
                int cur_r = r + drow[i];
                int cur_c = c + dcol[i];
                if(cur_r>=0 && cur_r<m && cur_c>=0 && cur_c<n && visited[cur_r][cur_c]!=2 && grid[cur_r][cur_c]==1){
                    q.push({{cur_r,cur_c},t+1});
                    visited[cur_r][cur_c] = 2; 
                }
            }
            
        }
        for(int i = 0 ; i< m ; i ++){
                for(int j = 0 ; j<n ; j++){
                    if(visited[i][j]!=2 && grid[i][j]==1){
                        return -1;
                    }
                }
            }
        return tmax;

    }
};
