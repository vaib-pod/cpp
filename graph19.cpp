//743. network delay time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0 ; i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k] =0;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis+wt<dist[v]){
                    dist[v]=dis+wt;
                    pq.push({dis+wt,v});
                }

            }
        }
        int maxval = 0;
        for(int i = 1 ; i <= n;i++){
            maxval = max(maxval,dist[i]);
        }
        if(maxval == 1e9) return -1; 
        return maxval;

    }
};
