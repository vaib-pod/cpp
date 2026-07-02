class Solution {
	public:
	vector<int> zfunc(string &s){
	    int start = 0;
	    int n = s.size();
	    
	    vector<int> arr(n,0);
	    int l = 0;
	    int r = 0;
	    for(int i = 0 ; i < n;i++){
	        if (i < r) {
                arr[i] = min(r - i, arr[i - l]);
            }
            while (i + arr[i] < n && s[arr[i]] == s[i + arr[i]]) {
                arr[i]++;
            }
            if (i + arr[i] > r) {
                l = i;
                r = i + arr[i];
            }
	    }
	    return arr;
	    
	}
	vector<int> search(string &pat, string &txt) {
		// code here
		string s = pat + '-'+txt;
		
		vector<int> res;
		vector<int> z = zfunc(s);
		for (int i = pat.size()+1; i <z.size(); i++) {
			if (z[i] == pat.size()) {
				res.push_back(i - pat.size()-1);
			}
		}
		return res;
	}
};
