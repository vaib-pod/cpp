//907. sum of subarray minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        vector<int> left(n);
        int mod =(1e9+7);
        stack<int> st;
        
        for(int i = n-1 ; i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) {
                right[i] = n;
            }
            else{
                right[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = 0 ; i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) {
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }

    int total =0;
    for(int i = 0 ; i < n ; i++){
        int left_val = i - left[i];
        int right_val = right[i] - i;
        total = (total + ((long long)right_val*left_val*arr[i])%mod)%mod;
    }

    return total;

    }
};
