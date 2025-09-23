//1614. max nesting depth

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int max_d = 0;
       for(int i = 0 ; i < s.size();i++){
        if(s[i]=='('){
            depth++;
            if(depth>max_d){
            max_d = depth;
        }
        }
        else if(s[i]==')'){
            depth--;
        }
       }
        return max_d;
    }
};
