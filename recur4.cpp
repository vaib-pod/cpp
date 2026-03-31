//74. search a 2d matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n*m)-1;
        while(low<=high){
            int mid = (low+high)/2;
            int first = mid/m;
            int second =mid%m;
            if(matrix[first][second]==target){
                return true;
            }
            else if(matrix[first][second]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return false;
    }
};
