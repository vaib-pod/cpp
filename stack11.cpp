//85. maximal rectangle

class Solution {
private:
int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        int n = heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> st;
        for(int i = n-1 ; i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
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
            while(!st.empty() && heights[st.top()]>=heights[i]){
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

        for(int i = 0 ; i < n ; i++){
            int area = (heights[i] * (right[i]-left[i]-1));
            maxarea = max(maxarea,area);
        }
        return maxarea;   
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int j = 0 ;j < m;j++ ){
            int sum = 0; 
            for(int i = 0 ; i < n ; i ++){
                if(matrix[i][j]=='1'){
                    sum+=1;
                    prefix[i][j] = sum;
                }
                else{
                prefix[i][j] = 0;
                sum =0;
                }
            }
        
        }
        int maxar = 0;
        for(int i = 0 ; i < n; i ++){
            maxar = max(maxar, largestRectangleArea(prefix[i]));
        }

        return maxar;
    }
};
