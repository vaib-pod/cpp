//gfg . number of islands

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count = 0;
        vector<int> ans;
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(visited[row][col]==1){
                ans.push_back(count);
                continue;
            }
            visited[row][col]=1;
            count++;
            vector<int> dr = {-1,0,1,0};
            vector<int> dc = {0,1,0,-1};
            for(int i = 0 ; i < 4; i++){
                int adjr = row+dr[i];
                int adjc = col + dc[i];
                if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m && visited[adjr][adjc] == 1){
                    int newnode = row*m+col;
                    int adjnewnode = adjr*m+adjc;
                    if(ds.findUPar(newnode)!=ds.findUPar(adjnewnode)){
                        count--;
                        ds.unionBySize(newnode,adjnewnode);
                    }
                }
            }
            ans.push_back(count);
        }
        
        
        return ans;
    }
};
