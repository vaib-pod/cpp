//gfg . nearly sorted 

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int> , greater<int>> minheap;
        int ind = 0;
        
        for(int i = 0 ; i< n;i++){
            minheap.push(arr[i]);
            if(minheap.size()>k){
                arr[ind] = minheap.top();
                minheap.pop();
                ind++;
            }
            
        }
        while(!minheap.empty()){
            arr[ind] = minheap.top();
            minheap.pop();
            ind++;
        }
        
        
    }
};
