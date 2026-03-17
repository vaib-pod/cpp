//1011. capacity to ship packages within days D

class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int load = 0; 
        int day = 1;
        for(int i = 0 ; i < weights.size();i++){
            if(load+weights[i]>cap){
                day++;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxval = 0;
        int sum = 0;
        for(int i = 0 ; i < weights.size(); i++){
            maxval = max(maxval , weights[i]);
            sum+=weights[i];
        }

        int low = maxval; 
        int high = sum;
        while(low<=high){
            int mid = (low+high)/2;
            int day = findDays(weights,mid);
            if(day<=days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
