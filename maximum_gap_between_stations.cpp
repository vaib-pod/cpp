class Solution {
public:
    int maximumGap(string skill, string station) {
        vector<int>left;
        vector<int>right;

        int i = 0;
        int j = 0;
        while(i<skill.size()){
            if(skill[i]==station[j]){
                left.push_back(j);
                i++;j++;
            }
            else{
                j++;
            }
        }

        i = skill.size()-1 ; j = station.size()-1;
        while(i>=0){
            if(skill[i]==station[j]){
                right.push_back(j);
                j--;i--;
            }
            else{
                j--;
            }
        }
        reverse(right.begin(), right.end());
        int gap = 0;
        for(int x = 0 ; x <right.size()-1;x++){
            gap = max(gap,right[x+1]-left[x]);
        }
        return gap;
        
    }
};