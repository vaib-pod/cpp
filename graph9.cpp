//127. word ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            int steps = q.front().second;
            string word = q.front().first;
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0 ; i<word.size();i++){
                char original = word[i];
                for(char c = 'a' ; c<= 'z' ; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        } 
        return 0;
    }
};
