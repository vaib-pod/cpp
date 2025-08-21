//455. Assign Cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int start1 = 0;
        int start2 = 0;
        int count = 0;
        int n = g.size();
        if (g.size() == 0 || s.size() == 0){
            return 0;
        }
        while(start1< g.size() && start2 < s.size()){
            if(g[start1]==s[start2]){
                start1++;
                start2++;
                count++;
            }
            else if(g[start1]>s[start2]){
                start2++;
            }
            else if(g[start1]<s[start2]){
                start1++;
                start2++;
                count++;
            }
        }
        return count;
    }
};
