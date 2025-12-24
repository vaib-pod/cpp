//451. sort characters by frequency 

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> table;
        int n = s.size();
        for(int i = 0 ;i< n; i++){
            table[s[i]]++;
        }
        vector<pair<char,int>> arr(table.begin(),table.end());
        sort(arr.begin(), arr.end(), 
        [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second > b.second; 
            }
            return a.first < b.first;
            }
        );
        string res = "";
        for (const auto& p : arr) {
            res += string(p.second, p.first);
        }
        return res;
    }
};
