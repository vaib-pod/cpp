// 268. Missing Number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum2 =0;
        int n = nums.size();
        int sum1 = (n*(n+1))/2;

        for(int i =0;i<n;i++){
            sum2 += nums[i];
        }
        
        return (sum1-sum2);
    }
};
