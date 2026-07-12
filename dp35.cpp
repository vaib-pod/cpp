//368. largest divisible subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++) {
            hash[i] = i; 
        }
        for(int i = 0 ; i< n;i++){
            for(int prev = 0 ; prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[prev]+1>dp[i]){
                    dp[i]= 1+dp[prev];
                    hash[i]=prev;
                }
            }
        }
        int maxi = 0;
        int lastind =0;
        for(int i = 0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                lastind = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastind]);
        while(hash[lastind] != lastind){
            lastind=hash[lastind];
            ans.push_back(nums[lastind]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
