class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> L(26,-1) , R(26,-1);
        for (int i = 0; i < n; ++i) {
            if (L[s[i] - 'a'] == -1) {
                L[s[i] - 'a'] = i;
            }
            R[s[i] - 'a'] = i;
        }
        vector<vector<bool>> adj(26, vector<bool>(26, false));
        for (int u = 0; u < 26; ++u) {
            if (L[u] != -1) {
                for (int i = L[u]; i <= R[u]; ++i) {
                    adj[u][s[i] - 'a'] = true;
                }
            }
        }
        vector<bool> visited(26, false);
        stack<int> st;
        auto dfs1 = [&](auto& self, int u) -> void {
            visited[u] = true;
            for (int v = 0; v < 26; ++v) {
                if (adj[u][v] && !visited[v]) {
                    self(self, v);
                }
            }
            st.push(u);
        };
        for (int i = 0; i < 26; ++i) {
            if (L[i] != -1 && !visited[i]) {
                dfs1(dfs1, i);
            }
        }
        
        vector<vector<bool>> rev_adj(26, vector<bool>(26, false));
        for (int u = 0; u < 26; ++u) {
            for (int v = 0; v < 26; ++v) {
                rev_adj[v][u] = adj[u][v];
            }
        }
        fill(visited.begin(), visited.end(), false);
        vector<int> scc_id(26, -1);
        int current_scc = 0;

        auto dfs2 = [&](auto& self, int u) -> void {
            visited[u] = true;
            scc_id[u] = current_scc;
            for (int v = 0; v < 26; ++v) {
                if (rev_adj[u][v] && !visited[v]) {
                    self(self, v);
                }
            }
        };
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                dfs2(dfs2, u);
                current_scc++;
            }
        }
        vector<bool> is_sink(current_scc, true);
        for (int u = 0; u < 26; ++u) {
            if (L[u] == -1) continue;
            for (int v = 0; v < 26; ++v) {
                if (adj[u][v] && scc_id[u] != scc_id[v]) {
                    is_sink[scc_id[u]] = false;
                }
            }
        }
        vector<string> result;
        for (int i = 0; i < current_scc; ++i) {
            if (is_sink[i]) {
                int min_L = n, max_R = -1;
                for (int u = 0; u < 26; ++u) {
                    if (L[u] != -1 && scc_id[u] == i) {
                        min_L = min(min_L, L[u]);
                        max_R = max(max_R, R[u]);
                    }
                }
                result.push_back(s.substr(min_L, max_R - min_L + 1));
            }
        }
        return result;
    }

};
