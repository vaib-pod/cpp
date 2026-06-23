//gfg. sfj - shortest job first

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        sort(bt.begin(),bt.end());
        int waiting = 0;
        int total = 0; 
        for(int i = 0 ; i < n; i++){
            total+=waiting;
            waiting += bt[i];
        }
        return total/n;
    }
};
