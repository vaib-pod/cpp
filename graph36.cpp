//126. word ladder 2

class Solution {
    private:
    unordered_map<string, vector<string>> adj;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string& word, string& beginWord) {
        path.push_back(word);
        
        if (word == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            ans.push_back(validPath);
        } else {
            for (string& parent : adj[word]) {
                dfs(parent, beginWord);
            }
        }
    
        path.pop_back();
    }
    
    public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);
        dict.erase(beginWord);
        
        bool found = false;
        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            
            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        
                        temp[i] = c;

                        if (dict.find(temp) != dict.end()) {
                            nextLevel.insert(temp);
                            adj[temp].push_back(word); 
                            
                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                    temp[i] = originalChar; 
                }
            }
        for (const string& w : nextLevel) {
                dict.erase(w);
        
        }
        currentLevel = nextLevel;
    }
    if (found) {
            dfs(endWord, beginWord);
        }

        return ans;
}};
