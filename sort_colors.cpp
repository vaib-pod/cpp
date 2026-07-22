class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i]==0) c1++;
            else if(nums[i]==1) c2++;
            else c3++;
        }
        for (int j = 0; j<(nums.size()-c2-c3); j++){
            nums[j] = 0;
        }
         for (int k = (nums.size()-c2-c3) ; k<(nums.size()-c3); k++){
            nums[k] = 1;
        }
         for (int l=(nums.size()-c3); l<(nums.size()); l++){
            nums[l] = 2;
        }
    }
};