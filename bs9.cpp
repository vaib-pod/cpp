//875. koko eating bananas

class Solution {
public:
    long findTime(vector<int>& piles, int speed){
        long sum = 0 ; 
        for(int i = 0; i < piles.size();i++){
            sum+=ceil((double)(piles[i])/(double)(speed));
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxval = 0;
        for(int i = 0 ; i < piles.size();i++){
            maxval = max(piles[i],maxval);
        }
        int low = 1 ;
        int high = maxval;
        while(low<=high){
            int mid = (low+high)/2;
            long time = findTime(piles, mid);
            if(time<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;

    }
};
