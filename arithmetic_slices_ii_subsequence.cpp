class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> mp(n);
        int result = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j<i;j++){
                long long diff = (long long)nums[i] - (long long)nums[j];
                int count = 0;
                if(mp[j].find(diff)!=mp[j].end()){
                    count = mp[j][diff];
                }
                
                result += count;
                mp[i][diff] += count+1;
            }
        }
        return result;
    }
};