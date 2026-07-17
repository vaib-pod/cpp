class DisjointSet{
    vector<int> size,parent;

public:
DisjointSet(int n){
    size.resize(n+1);
    parent.resize(n+1);
    for(int i = 0 ; i<=n;i++){
        size[i] = 1;
        parent[i] = i;
    }
}
int findUPar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node] = findUPar(parent[node]);
}
void unionBySize(int u, int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if(ulp_u == ulp_v){
        return;
    }
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v] = ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        DisjointSet ds(26);
        for(int i = 0 ; i < n;i++){
            if(equations[i][1]=='='&&equations[i][2]=='='){
            int node1 = equations[i][0]-'a';
            int node2 = equations[i][3] - 'a';
            ds.unionBySize(node1,node2);
            }
        }
        for(int i = 0 ; i < n;i++){
            if(equations[i][1]=='!'&&equations[i][2]=='='){
            int node1 = equations[i][0]-'a';
            int node2 = equations[i][3] - 'a';
            if(ds.findUPar(node1)==ds.findUPar(node2)){
                return false;
            }
            }
        }
        return true;
        
    }
};