//216. Combination sum III

class Solution {
public:
    void findcombo(int ind, int target,int size , vector<vector<int>>& ans, vector<int> &ds){
        if(target==0 && ds.size()==size){
            ans.push_back(ds);
            return;
        }
        if(target<= 0 || ds.size()>size) return;
        for(int i = ind ; i<=9 ; i++){
            if(i>target) break;
            ds.push_back(i);
            findcombo(i+1,target-i,size,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        findcombo(1,n,k,ans,ds);
        return ans;
    }
};
