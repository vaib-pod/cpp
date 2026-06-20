//72.edit distance

class Solution {
public:
    int f(int i, int j,string &word1, string &word2,vector<vector<int>>& dp ){
        int n1 = word1.size();
        int n2 = word2.size();
        if(i==n1) return n2-j;
        if(j==n2) return n1-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return f(i+1,j+1,word1,word2,dp);
        return dp[i][j] = 1 + min(f(i+1,j,word1,word2,dp),min(f(i,j+1,word1,word2,dp),f(i+1,j+1,word1,word2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(0,0,word1,word2,dp);
    }
};
