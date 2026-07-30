class Solution {
public:
    int minimumPushes(string word) {
        int push = 0;
        int count=1;
        int n = word.size();
        for(int i = 0 ; i < n;i++){
            if(count<=8) push+=1;
            if(count>8 && count<=16) push+=2;
            if(count>16 && count<=24) push+=3;
            if(count>24) push+=4;
            count++;
        }
        return push;
    }
};