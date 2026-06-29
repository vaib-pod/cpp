//1976. number of ways to arrive at destination 

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        int mod =1e9+7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int v = it.first;
                long long wt = it.second;
                if(dis+wt<dist[v]){
                    dist[v]=dis+wt;
                    pq.push({dist[v],v});
                    ways[v] = ways[node];
                }
                else if(dis+wt==dist[v]){
                    ways[v]=(ways[v]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;

    }
};
