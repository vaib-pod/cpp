//189 Rotate Array

// O(1) approach is to reverse k elements from last , reverse n-k elements from first and then reverse whole array.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        if(k>n){
            k=k%n;
        }
        for(int i = n-k;i<n;i++){
            arr.push_back(nums[i]);
        }
        for(int j = 0;j<n-k;j++){
            arr.push_back(nums[j]);
        }
        nums.swap(arr);
    }
};
