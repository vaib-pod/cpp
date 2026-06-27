//23. merge k sorted lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*> , vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minheap;
        int k = lists.size();
        for(int i = 0 ; i < k;i++){
            if(lists[i]!=NULL) minheap.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy= new ListNode(-1);
        ListNode* temp = dummy;
        while(!minheap.empty()){
            ListNode* newNode = minheap.top().second;
            temp->next = newNode;
            minheap.pop();
            if(newNode->next!=NULL){
                minheap.push({newNode->next->val,newNode->next});
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
