//gfg. djikstra algo

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0 ; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u, wt});
        }
        set<pair<int,int>> st;
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(wt+dis<dist[v]){
                    if(dist[v]!=INT_MAX){
                        st.erase({dist[v],v});
                    }
                    
                    dist[v] = dist[node]+wt;
                    st.insert({dist[v],v});
                }
            }
            
        }
        
        return dist;
    }
};
