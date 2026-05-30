//130. surrounded regions

class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>> &visited , int r, int c){
        int m = board.size();
        int n = board[0].size();

        if(r<0 || r>=m || c<0 || c>=n || board[r][c]!='O' || visited[r][c]){
            return;
        }
        visited[r][c] = 1;
        dfs(board, visited, r-1 ,c );
        dfs(board, visited, r ,c-1 );
        dfs(board, visited, r ,c+1 );
        dfs(board, visited, r+1 ,c );
        
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0 ; i< n ; i++){
            if(board[0][i]=='O'){
                dfs(board,visited,0,i);
            }
            if(board[m-1][i]=='O'){
                dfs(board,visited,m-1,i);
            }
        }
        for(int i = 0 ; i< m ; i++){
            if(board[i][0]=='O'){
                dfs(board,visited,i,0);
            }
            if(board[i][n-1]=='O'){
                dfs(board,visited,i,n-1);
            }
        }
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j]=='O'&& !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
