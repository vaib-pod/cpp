//gfg. activity selection

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        if (n == 0) return 0;
        vector<pair<int, int>> activities(n);
        for(int i = 0; i < n; i++) {
            activities[i] = {finish[i], start[i]};
        }
        sort(activities.begin(), activities.end());
        int count = 1;
        int last = activities[0].first;
        for(int i = 1; i < n; i++) {
            if(activities[i].second > last) {
                count++;
                last = activities[i].first;
            }
        }
        
        return count;
        
    }
};
