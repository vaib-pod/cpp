//115. Distinct Subsequences

class Solution {
public:
    int f(int i,int j, string &s, string &t,vector<vector<int>> &dp){
        int n1 = s.size();
        int n2 = t.size();
        if(j==n2) return 1;
        if(i==n1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = f(i+1,j+1,s,t,dp) + f(i+1,j,s,t,dp);
        }
        return dp[i][j] = f(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(0,0,s,t,dp);
    }
};
