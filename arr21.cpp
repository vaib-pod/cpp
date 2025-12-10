//1248. count number of nice subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarray(nums,k) -subarray(nums,k-1);
}

private : 
    int subarray(vector<int>& nums, int k){
    int n = nums.size();
        int left = 0 ; 
        int right = 0 ; 
        int count = 0; 
        int odd = 0 ; 
        while(right<n){
            if(nums[right]%2==1){
                odd++;
            }
            while(odd>k){
                if(nums[left]%2==1){
                    odd--;
                }
                left++;
            }
        
        count+=right - left+1;
        
        right++;
        
        

        }
        return count;
    }
};


