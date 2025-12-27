//5. Longest palindromic substring


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;

        for(int i = 0 ; i < n ; i++){
            int odd = longest(s,i,i);
            int even = longest(s,i,i+1);
            int maxlen = max(odd,even);

            if (maxlen > end - start) {
                start = i - (maxlen - 1) / 2;
                end = i + maxlen / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
private:
    int longest(const string& t, int left, int right){
        while(left>=0 && right<t.size() && t[left]==t[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};
