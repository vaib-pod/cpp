//242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
  if (s.length() != t.length()){
    return false;}
        int freq[26]= {0};
        int n1 = s.size();
        int n2 = t.size();
        bool expression = true;
        for(int i =0;i<n1;i++){
            freq[s[i]-'a']++;
        }
        for(int j =0;j<n2;j++){
            freq[t[j]-'a']--;
        }
        for(int k = 0; k<26;k++){
            if(freq[k]!=0){
                expression = false;
            }
        }
        return expression;
}

};
