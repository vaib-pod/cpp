//678. Valid parenthesis string

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int check =0;
        bool condition = true;
        for (int i = 0 ; i<n;i++){
            char c = s[i];
            if(c == '(' || c=='*'){
                check ++;
            }
            else if(c == ')'){
                check--;
            }
            if(check<0){
                condition = false;
            }
            

        }
        check = 0;
        for (int i = n-1 ; i>=0;i--){
            char c = s[i];
            if(c == ')' || c == '*'){
                check ++;
            }
            else if (c =='('){
                check --;
            }
            if(check<0){
                condition = false;
            }
          

        }
        return condition;
    }
};
