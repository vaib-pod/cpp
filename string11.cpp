//28. Find the Index of the First Occurrence in a String

class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1 = haystack.size();
        int s2 = needle.size();
        int i = 0;
        int index = -1;
        while(i < s1){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i,s2)==needle){
                    index = i;
                    break;
                }
            }
            i++;
        }
        return index;
    }
};
