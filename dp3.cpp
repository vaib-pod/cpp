// 213. house robber II

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i< n-1;i++){
            int current = max(nums[i]+prev2,prev);
            prev2 = prev;
            prev = current;
        }
        int ans1 = prev;
        prev = nums[1];
        prev2 = 0;
        for(int i = 2; i< n;i++){
            int current = max(nums[i]+prev2,prev);
            prev2 = prev;
            prev = current;
        }
        int ans2 = prev;

        return max(ans1,ans2);

    }
};
