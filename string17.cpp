//38. count and say

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string say = countAndSay(n-1);

        string result = "";
        for(int i = 0 ; i<say.size();i++){
            char c = say[i];
            int count = 1;
            while(i<say.size()-1 && c==say[i+1]){
                count++;
                i++;
            }
            result+=to_string(count)+(c);

        }
        return result;
    }
};
