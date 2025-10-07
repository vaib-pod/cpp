//35. search insert position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int start = nums[0];
        int end = nums[n-1];
        if(target > end){
            return n;
        }
        else if(target < start){
            return 0;
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            else if (nums[mid]>target){
                high=mid-1;
                
            }
            else if(nums[mid]<target){
                low = mid+1;
                
            }
            }
            return low;
        }
    };
