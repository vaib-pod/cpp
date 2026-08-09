class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }
        vector<int> depth(n, 0);
        int h = 0;
        queue<int> q;
        q.push(0);
        depth[0] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            h = max(h, depth[curr]);
            for (int child : adj[curr]) {
                depth[child] = depth[curr] + 1;
                q.push(child);
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (long long)nums[i] * (h - depth[i] + 1);
        }
        
        return sum;
    }
};