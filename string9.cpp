//921. minimum add to make parenthesis valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i]=='('){
                count1++;
            }
            else if(s[i]==')'){
                if(count1>0){
                    count1--;
                }
                else{
                    count2++;
                }
            }
        }
        return count1+count2;
        
        
    }
};
