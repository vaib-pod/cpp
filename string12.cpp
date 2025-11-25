//1021 remove outermost parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string s1 = "";
        for(char ch : s){
            if(ch=='('){
                if(level>0){
                    s1+=ch;
                }
                level++;
            }
            else if(ch==')'){
                level--;
                if(level>0){
                    s1+=ch;
                }
                
            }
        }
        return s1;
    }
};
