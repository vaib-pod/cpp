//gfg. MST : prim's algorithm

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0 ; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int>>> pq;
		vector<int> vis(V, 0);
		pq.push({0,0});
		int sum = 0;
		while(!pq.empty()){
		    auto it = pq.top();
		    int node = it.second;
		    int cost = it.first;
		    pq.pop();
		    if (vis[node] == 1) continue;
		    vis[node] = 1;
		    sum+=cost;
		    for (auto iter : adj[node]) {
				int adjNode = iter.first;
				int edW = iter.second;
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
    }
};
