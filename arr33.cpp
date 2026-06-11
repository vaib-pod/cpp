//992. subarrays with k diff integers

class Solution {
public:
    int sub(vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int,int> hash;
        int n = nums.size();
        while(right<n){
            if(hash[nums[right]]==0){
                k--;
            }
            hash[nums[right]]++;
            while(k<0){
                hash[nums[left]]--;
                if(hash[nums[left]]==0){
                    k++;
                }
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sub(nums,k) - sub(nums,k-1);
    }
};
