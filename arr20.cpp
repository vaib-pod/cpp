// 930. Binary subarray with sum 

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int k){
        int left = 0; 
        int right = 0 ; 
        int count = 0; 
        int n = nums.size();
        int sum = 0 ;
        while(right<n){
            if (k < 0) return 0;
            sum+=nums[right];
            
            while(sum>k){
                sum-=nums[left];
                left++;
            }

            count += right-left+1;
            right++;
            
        }
        return count;
    }
};
