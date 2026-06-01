//542. 01 matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            dist[r][c] = d;
            q.pop();
            for(int i = 0 ; i < 4 ; i ++){
                int cur_r = r + drow[i];
                int cur_c = c + dcol[i];
                if(cur_r>=0 && cur_r<m && cur_c>=0 && cur_c<n && visited[cur_r][cur_c]==0){
                    q.push({{cur_r,cur_c},d+1});
                    visited[cur_r][cur_c] = 1; 
                }
            }
            
        }
    return dist;
    }
};
