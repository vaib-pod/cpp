//583. delete operations for two strings

class Solution {
public:
    int f(int ind1, int ind2, string &word1, string &word2,vector<vector<int>> &dp){
        int n1 = word1.size();
        int n2 = word2.size();
        if(ind1==n1 || ind2==n2) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2]){
            return dp[ind1][ind2] = 1+ f(ind1+1,ind2+1,word1,word2,dp);
        }
        return dp[ind1][ind2] = max(f(ind1+1,ind2,word1,word2,dp),f(ind1,ind2+1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1)); 
        return n1 + n2 - 2*f(0,0,word1,word2,dp);

    }
};
