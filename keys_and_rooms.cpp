class Solution {
public:
    void dfs(int node, vector<vector<int>> &rooms, vector<int> &visited) {
        visited[node] = 1;
        for(auto it : rooms[node]){
            if(!visited[it]){
                dfs(it,rooms,visited);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        dfs(0,rooms,visited);
        for(int i = 0 ; i < rooms.size();i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};