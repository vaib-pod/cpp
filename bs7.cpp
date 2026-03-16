//1283. find the smallest divisor 

class Solution {
public:
    int dividesum(vector<int>& arr, int mid){
        int sum = 0; 
        int n = arr.size();
        for(int i = 0 ; i < n; i++){
            sum+=ceil((double)(arr[i])/(double)(mid));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int val = 0;
        for(int i = 0 ; i < nums.size();i++){
            val = max(val,nums[i]);
        }

        int low = 1; 
        int high = val;
        while(low <= high){
            int mid = (low+high)/2;
            if(dividesum(nums,mid)<=threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return low;
    }
};
