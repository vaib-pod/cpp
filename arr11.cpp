//54. Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> arr;
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int top = 0;
        int right = m -1 ;
        int bottom = n-1;

        while(left<=right && top<=bottom){
            for(int i = left; i<=right; i++){
                arr.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i<=bottom;i++){
                arr.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            for(int i = right; i>=left ; i--){
                arr.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(left<=right)
            for(int i = bottom; i>=top;i--){
                arr.push_back(matrix[i][left]);
            }
            left++;
        }
        return arr;

    }
};
