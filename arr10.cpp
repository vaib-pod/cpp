//1539. Kth missing positive number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int index = 0;
        int t = 0;
        int i = 0;
        bool found = false;
        while(i<arr.size()){
            if(arr[i]-t==0){
                t=arr[i];
                i++;
            }
            else if(arr[i]-t!=0){
                index += arr[i]-t-1;
                t = arr[i];
                if(index >= k){
                    found = true;
                    return (t-(index-k+1));
                }
            }
        }
        if(found == false){
            return (t+k-index);
        }
        return -1;
    }
};
