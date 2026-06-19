//1143. longest common subsequence

class Solution {
public:
    int f(int ind1, int ind2, string &text1, string &text2,vector<vector<int>> &dp){
        int n1 = text1.size();
        int n2 = text2.size();
        if(ind1==n1 || ind2==n2) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]){
            return dp[ind1][ind2] = 1+ f(ind1+1,ind2+1,text1,text2,dp);
        }
        return dp[ind1][ind2] = max(f(ind1+1,ind2,text1,text2,dp),f(ind1,ind2+1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1)); 
        return f(0,0,text1,text2,dp);
    }
};
