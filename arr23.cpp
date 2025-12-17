//73. Set matrix zero


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> arr;
        for(int i = 0;i<m;i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j]==0){
                    arr.push_back({i,j});
                }
            }
        }

        int x = arr.size();
        for(int i = 0 ; i<x ; i ++){
            int row = arr[i][0];
            int col = arr[i][1];

    
            fill(matrix[row].begin(), matrix[row].end(), 0);

        
            for(int k = 0; k < m; k++){
                matrix[k][col] = 0;
            }
        }
    }
};
