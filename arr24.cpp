//1838. Frequency of most frequent element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long n = nums.size();
        long long count = 1;
        sort(nums.begin(),nums.end());
        long long left = 0;
        long long right= 0;
        long long value = 0; 
        while(right<n){
            value+=nums[right];

            while((long long)(right-left+1)*nums[right]-value>k){
                value-=nums[left];
                left++;

            }
            count = max(count, right-left+1);
            right++;
        }
        return count;
    }
};
