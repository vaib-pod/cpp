//1631. Path With Minimum Effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        dist[0][0] = 0;
        q.push({0,{0,0}});
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {-1,0,1,0};
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r ==n-1 && c==m-1) return diff;
            for(int i = 0 ; i < 4 ; i++){
                int newr = r+dr[i];
                int newc = c+dc[i];
                if(newr>=0 && newr<n && newc>= 0 && newc < m){
                    int eff = max(abs(heights[newr][newc]-heights[r][c]),diff);
                    if(eff<dist[newr][newc]){
                        dist[newr][newc] = eff;
                        q.push({eff,{newr,newc}});
                    }
                }
            }
        }
        return 0;

    }
};
