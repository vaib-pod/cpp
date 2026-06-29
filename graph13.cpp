//gfg . shortest path in undirected graph
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        queue<int> q; 
        vector<int> ans(V,-1);
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
            
        }
        
        for(int i = 0 ; i< V; i++){
            if(dist[i]!=INT_MAX){
                ans[i] = dist[i];
            }
        }
        return ans;
        
    }
};
