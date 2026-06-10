//22. generate parenthesis

class Solution {
public:
    void findcombo(int n , int open , int close , string ds, vector<string> & ans){
        if(ds.size()==2*n){
            ans.push_back(ds);
            return;
        }

        if(open<n) findcombo(n,open+1,close,ds+"(",ans);
        if(close<open) findcombo(n,open,close+1,ds+")",ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds = "";
        findcombo(n,0,0,ds,ans);
        return ans;
    }
};
