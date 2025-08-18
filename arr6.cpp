//leaders in array

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
         int max = nums[n - 1];
        arr.push_back(nums[n-1]);
        for(int i = n-2 ; i>=0;i-- ){
            if(nums[i]>max){
                arr.push_back(nums[i]);
                max = nums[i];
            }
        }
        return reverse(arr.begin(), arr.end());;
    }
};
