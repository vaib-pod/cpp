//846. hand of straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0){
            return false;
        }
        unordered_map<int,int> cardCount;
        for(int i = 0 ; i< n;i++){
            cardCount[hand[i]]++;
        }
        priority_queue<int, vector<int> , greater<int>> minheap;

        for(auto const& pair : cardCount){
            minheap.push(pair.first);
        }
        while(!minheap.empty()){
            int first = minheap.top();
            if(cardCount[first]==0){
                minheap.pop();
                continue;
            }
            int group = cardCount[first];
            for(int i = 0 ; i < groupSize;i++){
                int curr = first+i;
                if(cardCount[curr]<group){
                    return false;
                }
                cardCount[curr] -=group;
            }
            minheap.pop();
        }
        return true;


    }
};
