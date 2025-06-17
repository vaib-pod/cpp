//Finding largest elemnet in an array

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int max = nums[0] ;
        int length = nums.size();
        for(int i = 1; i< length;i++){
            if (nums[i] > max){
                max = nums[i];
            }
        }
        return max;

    }
};
