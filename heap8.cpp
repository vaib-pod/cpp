//347. top k frequent elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        for(auto it : mp){
            minheap.push({it.second,it.first});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        vector<int> result;
        while(!minheap.empty()){
            result.push_back(minheap.top().second);
            minheap.pop();
        }
        return result;
    }
};
