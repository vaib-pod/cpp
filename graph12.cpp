//802. find eventual safe states

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        queue<int> q;
        vector<int> ans;
        vector<int> inDegree(V,0);
        for(int i = 0 ; i< V ;i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                inDegree[i]++;
            }
        }

        for(int i = 0 ; i < V ; i ++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
