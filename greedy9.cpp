//45. jump game II

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int curr = 0;
        int far = 0;
        for(int i = 0 ; i < n-1 ; i++){
            far = max(far,i+nums[i]);
            if(i==curr){
                jumps++;
                curr = far;
            }
        }
        return jumps;

    }
};
