//1048. longest string chain 

class Solution {
public:
    bool static compare(string&s , string &t){
        return s.size()<t.size();
    }
    bool possible(string &s, string &t){
        if(s.size()!=t.size()+1) return false;

        int pt1 = 0;
        int pt2 = 0;
        while(pt1<s.size()){
            if(s[pt1]==t[pt2] && pt2<t.size()){
                pt1++;
                pt2++;
            }
            else{
                pt1++;
            }
            
        }
        if(pt1==s.size()&&pt2==t.size()) return true;
            return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        vector<int> dp(n,1);
        int maxlen = 0 ;
        for(int i = 0 ; i < n ; i ++){
            for(int prev = 0 ; prev<i;prev++){
                if(possible(words[i],words[prev]) && dp[prev]+1>dp[i]){
                    dp[i]= dp[prev]+1;
                }
            }
            maxlen = max(maxlen,dp[i]);
        }
        return maxlen;
    }
};
