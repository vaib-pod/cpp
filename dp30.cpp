//132. Palindrome Partioning II

class Solution {
public:
    bool isPalindrome(int i ,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,string&s,vector<int> & dp){
        int n = s.size();
        if(i==n) return 0;
        int minCost = INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int ind = i; ind<n ;ind++){
            if(isPalindrome(i,ind,s)){
                int cost = 1 + f(ind+1,s,dp);
                minCost = min (minCost,cost);
            }
        }
        return dp[i] = minCost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp)-1;
    }
};
