// 118 pascal's triangle 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        if (numRows == 0) {
            return arr;
        }
        arr.push_back({1});
        int i = 2; 
        for (int i = 1; i < numRows; i++) {
            vector<int> newRow;
            newRow.push_back(1);
            for (int j = 1; j < i; j++) {
                int value = arr[i - 1][j - 1] + arr[i - 1][j];
                newRow.push_back(value);
            }
            newRow.push_back(1);
            arr.push_back(newRow);
        }
        return arr;
    }
};
