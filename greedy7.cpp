//gfg. minimum platform

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        
        int n = arr.size();
        vector<pair<int,int>> train(2*n);
        for(int i = 0 ; i < n;i++){
            train[i] = {arr[i],0};
        }
        for(int i = 0 ; i < n;i++){
            train[n+i] = {dep[i],1};
        }
        sort(train.begin(),train.end());
        int count = 0;
        int maxi = 0;
        for(int i = 0 ; i< 2*n; i++){
            if(train[i].first==0){
                count++;
            }
            else{
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;
        
    }
};
