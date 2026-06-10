//78. subsets

class Solution {
public:
    void findcombo(vector<int>& nums , int ind , vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);
        int n = nums.size();
        for(int i = ind; i<n;i++ ){
            ds.push_back(nums[i]);
            findcombo(nums,i+1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        findcombo(nums,0,ds,ans);
        return ans;
    }
};
