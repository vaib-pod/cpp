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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(int i = 0 ; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            ds.unionBySize(u,v);
        }
        vector<int> compSize(n,0);
        for(int i = 0 ; i <n;i++){
            compSize[ds.findUPar(i)]++;
        }

        long long remaining = n;
        long long unreachable = 0;
        for(int i = 0; i< n;i++){
            if(compSize[i]>0){
                remaining-= compSize[i];
                unreachable+=(remaining*compSize[i]);
            }
        }
        return unreachable;
    
    }
};