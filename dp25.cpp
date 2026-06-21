//44. wildcard matching


class Solution {
public:
    bool f(int i , int j, string&s, string & p,vector<vector<int>>& dp){
        int n1 = p.size();
        int n2 = s.size();
        if(i==n1 && j==n2) return true;
        if(j==n2 && i<n1){
            for(int ind = n1-1 ; ind>=i;ind--){
                if(p[ind]!='*') return false;
            }
            return true;
        }
        if(i==n1 && j<n2) return false;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[j]==p[i] || p[i]=='?'){
            return dp[i][j] = f(i+1,j+1,s,p,dp);
        }
        if(p[i]=='*'){
            return dp[i][j] = f(i+1,j,s,p,dp) | f(i,j+1,s,p,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n1 = p.size();
        int n2 = s.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(0,0,s,p,dp);
    }
};
