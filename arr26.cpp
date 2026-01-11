//1358. number of substrings containing all 3 characters
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> hash(3,-1);
        int l = 0 ;
        int count = 0 ;

        for(int r =0; r < n ; r ++){
            hash[s[r]-'a'] = r;
            if(hash[0]!= -1 && hash[1]!= -1 && hash[2]!= -1 ){
                count += 1+min(min(hash[0],hash[1]),hash[2]);
            }
            
        }
        return count;
        
    }
};
