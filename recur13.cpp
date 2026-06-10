//17. letter combinations of a phone number

class Solution {
public:
    void findcombo(int ind, string& digits, string& ds, vector<string>& ans, const vector<string>& mapping) {
        if (ind == digits.length()) {
            ans.push_back(ds);
            return;
        }
        int currdig = digits[ind] -'0';
        string word = mapping[currdig];
        for(int i = 0 ; i<word.length();i++){
            ds.push_back(word[i]);
            findcombo(ind+1, digits, ds , ans , mapping);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds = "";
        if (digits.empty()) return ans;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        findcombo(0, digits, ds, ans, mapping);
        return ans;
    }
};
