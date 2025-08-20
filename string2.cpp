//151. Reverse Words in a String


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss>>word){
            words.push_back(word);
        }

        string result = "";
        if (words.empty()) {
            return result;
        }

        for(int i = words.size()-1;i>=0;--i){
            result+=words[i];
            if (i != 0) {
                result += " ";
            }
        }
        return result;
    }
};
