//1423. Max points you can obtain from cards


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int start = 0 ; 
        int end = n-1;
        int minsum = INT_MAX;
        int sum = 0;
        int arrsum = 0 ; 
        for(int i = 0 ; i < n ; i ++){
            arrsum += cardPoints[i];
        }
        if(k==n) return arrsum;
        for(int i = 0 ; i<n-k;i++){
            sum+=cardPoints[i];
        }
        if(sum<minsum){
                minsum = sum;
            }
        for(int i = n-k ; i<n;i++){
            sum = sum - cardPoints[i-(n-k)]+cardPoints[i];
            if(sum<minsum){
                minsum = sum;
            }
        }

        int result = arrsum-minsum;
        return result ; 
    }
};
