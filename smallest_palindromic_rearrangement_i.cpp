class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>hash(26,0);
        for(int i = 0 ; i<s.size();i++){
            hash[s[i]-'a']++;
        }

        string t ="";
        char mid = '@';
        for(int i = 0 ; i < 26 ; i++){
            if(hash[i]>0){
                int x = hash[i]/2;
                for(int j = 0 ; j < x ; j ++){
                    t+='a'+i;
                }
                if(hash[i]%2==1){
                    mid = 'a'+i;
                }
            }
        }
        string j = t;
        if(mid!='@'){
            t+=mid;
        }
        reverse(j.begin(),j.end());
        t+=j;

        return t;
    }
};