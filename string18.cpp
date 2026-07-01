//686. repeated string match

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string result = "";
        while(result.size()<b.size()){
            result += a;
            count++;
        }
        if(result.find(b)!=string::npos){
            return count;
        }
        result+=a;
        count++;
        if(result.find(b)!=string::npos){
            return count;
        }
        return -1;

    }
};
