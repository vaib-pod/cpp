//778. swim in rising water

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int current_max = it[0];
            int r = it[1];
            int c = it[2];
            if (r == n - 1 && c == n - 1) {
                return current_max;
            }
            for (int i = 0; i < 4; i++) {
                int adjr = r + dr[i];
                int adjc = c + dc[i];
                if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n && visited[adjr][adjc] == 0) {
                    visited[adjr][adjc] = 1;
                    int new_max = max(current_max, grid[adjr][adjc]);
                    pq.push({new_max, adjr, adjc});
                }
            }
        }
        return 0;
    }
};
