//410. split array largest sum

class Solution {
public:
    int allocate(vector<int>& nums, int mid){
        int intervals = 1;
        int sum = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i]+sum<=mid){
                sum+=nums[i];
            }
            else{
                sum = nums[i];
                intervals++;
            }
        }
        return intervals;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int maxval = 0;
        for(int i = 0; i < nums.size();i++){
            sum+=nums[i];
            maxval = max(maxval,nums[i]);
        }   

        int low = maxval ;
        int high = sum;
        int res = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(allocate(nums,mid)<=k){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};
