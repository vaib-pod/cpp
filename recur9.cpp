//40. Combination sum II

class Solution {
public:
    void findcombo(int ind, int target, vector<int>& arr , vector<vector<int>>& ans, vector<int> &ds){
        int n = arr.size();
        if(target==0){
            ans.push_back(ds);
        }
        for(int i = ind ; i<n ; i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findcombo(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        findcombo(0,target,candidates,ans,ds);
        return ans;
    }
};
