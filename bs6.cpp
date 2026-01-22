//81. search in rotated sorted array II

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        
        if(n==1 && nums[0]==target) return true;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                start++;
                end--;
                continue;
            }
            if(nums[start]<=nums[mid]){
                if(target>=nums[start] && target<nums[mid]){
                end = mid-1;
            }
            else{
                start=mid+1;
            }

            }
            else{
            if(target<=nums[end] && nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }}
        }
        return false;
    }


};
