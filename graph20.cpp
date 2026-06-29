//gfg. min multiplications

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code 
        if (start == end) return 0;
        queue<pair<int,int>> q;
        vector<int> dist(1000,1e9);
        dist[start] = 0;
        int mod = 1000;
        q.push({0,start});
        while(!q.empty()){
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            for(auto it : arr){
                int num = (it*node)%1000;
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    if(num==end) return steps+1;
                    q.push({steps+1,num});
                }
            }
        }
        return -1;
    }
};
