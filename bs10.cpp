//1482. min no. of days tomake m bouquets

class Solution {
public:
    int possible(vector<int>& arr, int day, int m, int k){
        int count = 0;
        int bouquet =0;
        for(int i = 0 ; i < arr.size();i++){
            if(arr[i]<=day){
                count++;
                if(count==k){
                    bouquet++;
                    count=0;
                }
            }
            else{
                count = 0;
            }
        }
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int mini = bloomDay[0];
        int maxi = 0;
        for(int i = 0 ; i < bloomDay.size();i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        int result = -1;
        while(low<=high){
            int mid = (low+high)/2;
            int bouquet = possible(bloomDay,mid,m,k);
            if(bouquet>=m){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return result;
    }
};
