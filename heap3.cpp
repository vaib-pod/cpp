//gfg. replace elements by rank

class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        int n = arr.size();
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        for(int i = 0 ; i<n;i++){
            minheap.push({arr[i],i});
        }
        int rank = 0;
        while(!minheap.empty()){
            int index = minheap.top().second;
            minheap.pop();
            arr[index] = rank;
            rank++;
        }
    }
};
