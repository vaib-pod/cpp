//33. search in rotated array


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int index = -1;
        if(n==1 && nums[0]==target) return 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid]==target){
                return mid;
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
        return index;
    } 
};
