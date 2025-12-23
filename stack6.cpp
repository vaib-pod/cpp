//402. Remove K digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        stack<char> st;

        for(int i = 0 ; i <n;i++){
            
            while(!st.empty()&& k>0 && num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string res ="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        while( res.size()>0 && res.back()=='0'){
            res.pop_back();
        }
        if(res.size()==0) return "0";

        reverse(res.begin(),res.end());
        return res;
    }
};
