// 2149. Rearrange Array Elements by Sign

// initail approach was to create 2 arrays and store +ve and -ve values , and append them alternately at the end. 

// final approach : 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> newarr(n);
        int posind = 0;
        int negind = 1;
        for(int i = 0; i <n ;i++){
            if(nums[i]>0){
                newarr[posind] = nums[i];
                posind+=2;
            }
            else{
                newarr[negind] = nums[i];
                negind+=2;
            }
        }
        return newarr;
    }
};
