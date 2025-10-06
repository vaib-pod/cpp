//55. jump game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump =0;
        int n = nums.size();


        for(int i = 0 ; i<n;i++){
            if(i > maxjump) return false;
            maxjump = max(maxjump,i+nums[i]);
        }
        return true;
    }
};
