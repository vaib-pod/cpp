//56 . merge intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> result;
        if(n==1) return intervals;
        
        for(int i = 0 ; i < n ; i++){
            if(result.empty() || result.back()[1]<intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            
        }
        return result;
    }
};
