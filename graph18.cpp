//787. cheapest flights within k stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int cost = it.second.second;
            int node = it.second.first;
            if(stops>k) continue;
            for(auto i : adj[node]){
                int v = i.first;
                int wt = i.second;
                if(cost+wt<dist[v]){
                    dist[v] = cost+wt;
                    q.push({stops+1,{v,cost+wt}});
                }
            }

        }
        if(dist[dst]== 1e9) return -1;
        return dist[dst];

    }
};
