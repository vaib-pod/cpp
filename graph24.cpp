//1192. critical connections in a network


class Solution {
public:
    int timer = 1 ;
    void dfs(int node , int parent, vector<int> &vis,vector<vector<int>> &adj,vector<int> &tin,vector<int> &low,vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = low[node]= timer;
        timer++;
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,tin,low,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i = 0  ; i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<vector<int>> bridges;
        vector<int> tin(n);
        vector<int> low(n);
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;

    }
};
