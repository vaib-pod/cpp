//gfg. maximum sum combination 

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int> ans;
        priority_queue<pair<int,int>> pq; 
        int n = a.size();
        for(int i = 0 ; i<n;i++){
            pq.push({a[i]+b[n-1],n-1});
        }
        
        while(!pq.empty()&& k--){
            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            ans.push_back(val);
            if(ind-1>=0){
                int sum = val-b[ind]+b[ind-1];
                pq.push({sum,ind-1});
            }
        }
        return ans;
    }
};
