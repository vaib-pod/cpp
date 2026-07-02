//gfg. articulation point II

class Solution {
  public:
    int timer = 1 ;
    void dfs(int node , int parent, vector<int> &vis,vector<vector<int>> &adj,vector<int> &tin,vector<int> &low,vector<int> &mark){
        vis[node] = 1;
        tin[node] = low[node]= timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,tin,low,mark);
                low[node] = min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child>1 && parent == -1){
            mark[node] =1 ;
            
        }

    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        for(int i = 0  ; i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> mark(V,0);
        vector<int> bridges;
        vector<int> tin(V);
        vector<int> low(V);
        for(int i  = 0 ; i < V ; i ++){
            if(!vis[i]){
                dfs(i, -1, vis, adj, tin, low, mark);
            }
        }
        for(int i = 0 ; i < V;i++){
            if(mark[i]==1){
                bridges.push_back(i);
            }
        }
        if(bridges.size() == 0) return {-1};
        
        return bridges;
    }
};
