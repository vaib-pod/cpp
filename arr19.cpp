//1004. Maximum consecutive ones

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0 ; 
        int maxcount = 0 ;
        int n = nums.size();
        int left=0;
        int right =0;
        while(right<n){
            if(nums[right]==0){
                zero++;
            }
            while(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                left++;
                }
            
            int window = right-left+1;
            if(window>maxcount){
                maxcount = window;
            }
            right++;
        }
        return maxcount;
    }
};
