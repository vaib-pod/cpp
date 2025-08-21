// 14. Longest Common Prefix


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string word = strs[0];
       
        for(int i =1; i < n;i++){
            string empty ="";
            int j=0;
            int k=0;
            int n1 = word.size();
            for(int m = 0;m<n1;m++){
                if(strs[i][j]==word[k]){
                empty+=strs[i][j];
                j++;
                k++;
                }
            }
            word = empty;
        }
        return word;
    }
};
