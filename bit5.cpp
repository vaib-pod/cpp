//78. subsets


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int x = 1<<n;
        vector<vector<int>> arr;
        for(int i = 0; i < x ; i++){
            vector<int> temp ;
            for(int j = 0 ; j < n ; j++){
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            arr.push_back(temp);
        }
        return arr;
    }
};
