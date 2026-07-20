class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;
        arr[1]=1;
        for(int i = 2 ; i<=n;i++){
            int num2 = arr[i2]*2;
            int num3 = arr[i3]*3;
            int num5 = arr[i5]*5;
            int minval = min({num2,num3,num5});
            arr[i] = minval;

            if(minval==num2){
                i2++;
            }
            if(minval==num3){
                i3++;
            }
            if(minval==num5){
                i5++;
            }

        }
        return arr[n];

    }
};