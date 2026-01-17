//496. next greater element

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> next_greater;
        stack<int> st;
        for(int i = n-1 ; i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()) {
                next_greater[nums2[i]] = -1;
            }
            else{
                next_greater[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> arr;
        int m = nums1.size();
        for(int i = 0 ; i < m ; i++){
            if(next_greater.count(nums1[i])){
                arr.push_back(next_greater[nums1[i]]);
            }
            else{
                arr.push_back(-1);
            }
        }

        return arr;
    }
};
