//796. Rotate String

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size()!=goal.size()){
            return false;
        }
        if(s==goal){
            return true;
        }
        int n = goal.size();
        vector<string> arr;
        int k = 1;
        string j = goal;
        while(k < n){
            j.push_back(goal[0]);
            j.erase(0, 1);
            goal = j;
            if(goal == s){
                return true;
            }
        k++;
        }
        return false;
    }
};
