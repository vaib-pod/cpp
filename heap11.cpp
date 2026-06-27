//gfg. minimum cost to cut ropes

class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i = 0 ; i< n; i++){
            minheap.push(arr[i]);
        }
        int sum = 0 ; 
        while(minheap.size()>1){
            int min1 = minheap.top();
            minheap.pop();
            int min2 = minheap.top();
            minheap.pop();
            int current = min1+min2;
            sum+=current;
            minheap.push(current);
        }
        return sum;
        
    }
};
