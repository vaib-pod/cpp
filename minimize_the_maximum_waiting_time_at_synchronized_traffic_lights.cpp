class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxLight = 0;
        for(int i = 0 ; i < lights.size();i++){
            maxLight = max(maxLight,lights[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < arrivalTime.size();i++){
            int r = arrivalTime[i]%period;
            if(r>=maxLight){
                ans = max(ans,period-r);
            }
        }
        return ans;
    }
};